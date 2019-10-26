#!/usr/bin/env python3

import rospy
from captivity.msg import GameState as GameStateMsg
import tkinter as tk


class CurrentGameState:

    _game_state_dict = {0: 'IDLE', 1: 'RESET', 2: 'START', 3: 'END'}

    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._frame.grid(columnspan=2,
                         padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root

        self._InitSubscriberTopics()

        self._InitWidgets()

    def _InitWidgets(self):
        tk.Label(self._root,
                 text="""CURRENT GAME STATE""",
                 justify=tk.CENTER,
                 padx=0).pack(in_=self._frame, anchor=tk.N)

        self._canvas_width = 200
        self._canvas_height = 40
        self._canvas = tk.Canvas(self._root,
                                 width=self._canvas_width,
                                 height=self._canvas_height)

        self._canvas.pack(in_=self._frame)

        self._canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_state = self._canvas.create_text(self._canvas_width / 2,
                                                       self._canvas_height / 2,
                                                       text="Null")

    def _InitSubscriberTopics(self):
        rospy.Subscriber("game_state", GameStateMsg,
                         self._CurrentGameStateCallback)

    def _CurrentGameStateCallback(self, msg_in):
        rospy.loginfo(msg_in.game_state)

        new_state = self._game_state_dict[msg_in.game_state]
        self._canvas.itemconfig(self._current_state, text=new_state)
