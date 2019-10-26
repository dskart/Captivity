#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32
import tkinter as tk

from Visualizer.player_abstract import PlayerAbstract


class PlayerA(PlayerAbstract):

    def _InitFrame(self):
        self._frame.grid(row=0, column=0, padx=(10, 10), pady=(10, 10))

    def _InitLabel(self):
        tk.Label(self._root,
                 text="""PLAYER A""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

    def _InitWidgets(self):

        self._canvas_width = 120
        self._canvas_height = 40
        self._canvas = tk.Canvas(self._root,
                                 width=self._canvas_width,
                                 height=self._canvas_height)
        self._canvas.pack(in_=self._frame)

        self._canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_life = self._canvas.create_text(self._canvas_width / 2,
                                                      self._canvas_height / 2,
                                                      text="Null")

    def _InitSubscribers(self):
        rospy.Subscriber("player_A_health", Int32,
                         self._PlayerHealthStateCallback)

    def _PlayerHealthStateCallback(self, msg_in):
        rospy.loginfo(msg_in.data)

        new_health = msg_in.data
        self._canvas.itemconfig(self._current_life, text=str(new_health))
