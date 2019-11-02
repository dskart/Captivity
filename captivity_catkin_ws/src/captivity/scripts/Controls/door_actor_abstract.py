#!/usr/bin/env python3

import rospy
from captivity.msg import GameState
import tkinter as tk
import time
from abc import abstractmethod


class DoorActorAbstract:
    _scaring = 0
    _name = ""
    MAX_TIME = 10
    _user_locked = 0

    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._InitFrame()
        self._ros_node = ros_node
        self._root = root
        self._InitSubscribers()

        self._InitWidgets()

    @abstractmethod
    def _InitFrame(self):
        pass

    def _InitWidgets(self):
        self._v = tk.IntVar()

        self._actor_states = [
            ("HIDE", 0),
            ("SCARE", 1),
            ("GO", 2),
        ]

        self.label = tk.Label(self._root, justify=tk.CENTER)
        self.radio_buttons = {}
        self._InitLabel()

        for val, state in enumerate(self._actor_states):
            button = tk.Radiobutton(self._root,
                                    text=state,
                                    indicatoron=0,
                                    width=20,
                                    padx=20,
                                    variable=self._v,
                                    command=self._PublishActorState,
                                    value=val)
            button.pack(in_=self._frame, anchor=tk.N)
            self.radio_buttons[state[0]] = button

        self._UpdateClock()

    @abstractmethod
    def _InitLabel(self):
        pass

    @abstractmethod
    def _PublishActorState(self):
        pass

    @abstractmethod
    def _InitSubscribers(self):
        pass

    def _ActorStateCallBack(self, msg_in):
        self._v.set(msg_in.data)

        if msg_in.data == 2:
            self._PlayerLost()
            return

        if msg_in.data == 1 and not self._scaring:
            self._scaring = 1
            self._start_time = time.time()
        else:
            self._scaring = 0

    def _UpdateClock(self):
        if self._v.get() == 1 and self._scaring:
            time_left_str, time_left = self._CalculateTimeLeft()
            new_label = "TIME LEFT: " + time_left_str
            self.label.configure(text=new_label)

            if self._user_locked:
                self.radio_buttons["HIDE"].invoke()

            if time_left <= 0:
                self.radio_buttons["GO"].invoke()
        else:
            self.label.configure(text=self._name)

        self._root.after(1000, self._UpdateClock)

    def _CalculateTimeLeft(self):
        time_since_start = time.time() - self._start_time
        time_left = self.MAX_TIME - time_since_start

        time_left_str = time.strftime(
            "%H:%M:%S", time.gmtime(time_left))

        return time_left_str, time_left

    def _DoorEventCallBack(self, msg_in):
        if not msg_in.data:
            self._user_locked = 1
        else:
            self._user_locked = 0

    @abstractmethod
    def _PlayerLost(self):
        return
