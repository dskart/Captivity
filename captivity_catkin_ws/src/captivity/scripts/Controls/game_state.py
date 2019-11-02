#!/usr/bin/env python3

import rospy
from captivity.msg import GameState as GameStateMsg
import std_msgs
import tkinter as tk

import time
import json
import os


class GameState:
    # MAX_TIME = 60*15
    MAX_TIME = 5
    _EVENT_TIME = 60

    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._frame.grid(columnspan=2, padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root

        self.game_running = 0
        self._events_data = self._ImportJson()
        self._events_data_iter = iter(self._events_data)

        self._InitWidgets()

    def _InitWidgets(self):
        self._v = tk.IntVar()

        self._game_states = [
            ("IDLE", 0),
            ("RESET", 1),
            ("START", 2),
            ("END", 3),
        ]

        self._game_state_label = tk.Label(self._root,
                                          text="""""",
                                          justify=tk.CENTER)

        self._game_state_label.pack(in_=self._frame, anchor=tk.N)
        self._UpdateClock()

        self.radio_buttons = {}
        for val, state in enumerate(self._game_states):
            button = tk.Radiobutton(self._root,
                                    text=state,
                                    indicatoron=0,
                                    width=20,
                                    padx=20,
                                    variable=self._v,
                                    command=self._PublishGameState,
                                    value=val)

            button.pack(in_=self._frame, anchor=tk.N)
            self.radio_buttons[state[0]] = button

    def _UpdateClock(self):
        if self._v.get() == 2 and self.game_running:
            time_left_str, time_left = self._CalculateTimeLeft()
            new_label = "GAME STATE: " + time_left_str
            self._game_state_label.configure(text=new_label)

            # if self._TimePassedSinceLastEvent():
            # self._UpdateEvent()

            if time_left <= 0:
                self.radio_buttons["END"].invoke()
        else:
            self._events_data_iter = iter(self._events_data)
            self._game_state_label.configure(text="""GAME STATE""")

        self._root.after(1000, self._UpdateClock)

    def _CalculateTimeLeft(self):
        time_since_start = time.time() - self._start_time
        time_left = self.MAX_TIME - time_since_start

        time_left_str = time.strftime(
            "%H:%M:%S", time.gmtime(time_left))

        return time_left_str, time_left

    def _TimePassedSinceLastEvent(self):
        time_since_last_event = time.time() - self._last_event_time

        if time_since_last_event >= self._EVENT_TIME:
            self._last_event_time = time.time()
            return True

        return False

    def _UpdateEvent(self):
        event_data = next(self._events_data_iter)
        print(event_data)

    def _PublishGameState(self):
        game_state_msg = GameStateMsg()
        game_state_msg.player1 = 1
        game_state_msg.player2 = 1
        game_state_msg.game_state = self._v.get()

        rospy.loginfo(game_state_msg)
        self._ros_node.game_state_pub.publish(game_state_msg)

        #  STATE = RESET
        if self._v.get() != 2:
            self._ResetEveryPubValues()

        # first start set up timer
        if self._v.get() == 2 and not self.game_running:
            self.game_running = 1
            self._start_time = time.time()
            self._last_event_time = self._start_time
        else:
            self.game_running = 0

    def _ResetEveryPubValues(self):
        self._ResetMusicBoxes()
        self._ResetActors()

    def _ResetMusicBoxes(self):
        music_box_msg = std_msgs.msg.UInt8()
        music_box_msg.data = 1

        self._ros_node.music_box_state_pub.publish(music_box_msg)

    def _ResetActors(self):
        actor_msg = std_msgs.msg.UInt8()
        actor_msg.data = 0

        self._ros_node.front_door_actor_A_state_pub.publish(actor_msg)
        self._ros_node.front_door_actor_B_state_pub.publish(actor_msg)
        self._ros_node.back_door_actor_A_state_pub.publish(actor_msg)
        self._ros_node.back_door_actor_B_state_pub.publish(actor_msg)

    def _ImportJson(self):
        dir_path = os.path.dirname(os.path.realpath(__file__))
        dir_path += "/test_game.json"
        with open(dir_path) as f:
            data = json.load(f)

        self.MAX_TIME = data["max_time"]

        return data['events_data']
