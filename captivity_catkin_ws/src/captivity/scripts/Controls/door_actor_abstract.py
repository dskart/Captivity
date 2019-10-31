#!/usr/bin/env python3

import rospy
from captivity.msg import GameState
import tkinter as tk

from abc import abstractmethod


class DoorActorAbstract:
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

        self._InitLabel()

        for val, state in enumerate(self._actor_states):
            tk.Radiobutton(self._root,
                           text=state,
                           indicatoron=0,
                           width=20,
                           padx=20,
                           variable=self._v,
                           command=self._PublishActorState,
                           value=val).pack(in_=self._frame, anchor=tk.N)

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
