#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32, UInt8
import tkinter as tk

from Visualizer.player_abstract import PlayerAbstract


class PlayerA(PlayerAbstract):
    _monster_out = 0

    def _InitFrame(self):
        self._frame.grid(row=0, column=0, padx=(10, 10), pady=(10, 10))

    def _InitLabel(self):
        tk.Label(self._root,
                 text="""PLAYER A""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

    def _InitWidgets(self):
        self._canvas_width = 120
        self._canvas_height = 40
        self._life_canvas = tk.Canvas(self._root,
                                      width=self._canvas_width,
                                      height=self._canvas_height)
        self._life_canvas.pack(in_=self._frame, anchor=tk.N)

        self._life_rect = self._life_canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_life = self._life_canvas.create_text(self._canvas_width / 2,
                                                           self._canvas_height / 2,
                                                           text="Null")

        self._music_canvas = tk.Canvas(self._root,
                                       width=self._canvas_width,
                                       height=self._canvas_height)
        self._music_canvas.pack(in_=self._frame, anchor=tk.N)

        self._music_rect = self._music_canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_music_state = self._music_canvas.create_text(self._canvas_width / 2,
                                                                   self._canvas_height / 2,
                                                                   text="MUSIC BOX")

    def _InitSubscribers(self):
        rospy.Subscriber("player_A_health", Int32,
                         self._PlayerHealthStateCallback)
        rospy.Subscriber("music_box_A_state", UInt8,
                         self._MusicBoxStateCallBack)

        rospy.Subscriber("monster_A_out", UInt8, self._MonsterOutCallBack)

    def _PlayerHealthStateCallback(self, msg_in):
        rospy.loginfo(msg_in.data)

        new_health = msg_in.data
        self._life_canvas.itemconfig(self._current_life, text=str(new_health))

    def _MusicBoxStateCallBack(self, msg_in):
        rospy.loginfo(msg_in.data)

        if not self._monster_out:
            new_music_box_state = msg_in.data

            if new_music_box_state:
                self._music_canvas.itemconfig(self._music_rect, fill="green")
            else:
                self._music_canvas.itemconfig(self._music_rect, fill="yellow")

    def _MonsterOutCallBack(self, msg_in):
        if msg_in.data:
            self._music_canvas.itemconfig(self._music_rect, fill="red")
