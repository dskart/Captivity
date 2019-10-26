#!/usr/bin/env python3

import rospy
from captivity.msg import GameState
import tkinter as tk

from abc import abstractmethod


class PlayerAbstract:
    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._InitFrame()

        self._ros_node = ros_node
        self._root = root

        self._InitSubscribers()
        self._InitLabel()
        self._InitWidgets()

    @abstractmethod
    def _InitFrame(self):
        pass

    @abstractmethod
    def _InitLabel(self):
        pass

    @abstractmethod
    def _InitWidgets(self):
        pass

    @abstractmethod
    def _InitSubscribers(self):
        pass

    @abstractmethod
    def _PlayerHealthStateCallback(self):
        pass
