#!/usr/bin/env python3

import rospy
from captivity.msg import GameState as GameStateMsg
from std_msgs.msg import UInt8
import tkinter as tk


class MusicBox:
    _monster_out = 0

    # _game_state_dict = {0: 'IDLE', 1: 'RESET', 2: 'START', 3: 'END'}

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
        self._music_canvas = tk.Canvas(self._root,
                                       width=self._canvas_width,
                                       height=self._canvas_height)

        self._music_canvas.pack(in_=self._frame)

        self._music_rect = self._music_canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_state = self._music_canvas.create_text(self._canvas_width / 2,
                                                             self._canvas_height / 2,
                                                             text="MUSIC BOX")

    def _InitSubscriberTopics(self):
        rospy.Subscriber("music_box_state", UInt8,
                         self._MusicBoxCallBack)

        rospy.Subscriber("monster_A_out", UInt8, self._MonsterOutCallBack)

    def _MusicBoxCallBack(self, msg_in):

        if not self._monster_out:
            new_music_box_state = msg_in.data

            if new_music_box_state:
                self._music_canvas.itemconfig(self._music_rect, fill="green")
            else:
                self._music_canvas.itemconfig(self._music_rect, fill="yellow")

    def _MonsterOutCallBack(self, msg_in):
        if msg_in.data:
            self._music_canvas.itemconfig(self._music_rect, fill="red")
