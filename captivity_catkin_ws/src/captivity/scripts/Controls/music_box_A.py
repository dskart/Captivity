#!/usr/bin/env python3

import rospy
import std_msgs.msg
import tkinter as tk


class MusicBoxA:
    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        # self._frame.grid(row=2, column=0, padx=(10, 10), pady=(10, 10))
        self._frame.grid(columnspan=2, column=0,
                         padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root
        self._InitSubscribers()

        self._InitWidgets()

    def _InitWidgets(self):
        self._v = tk.IntVar()

        self._game_states = [
            ("STOP", 0),
            ("START", 1),
        ]

        tk.Label(self._root,
                 text="""MUSIC BOX""",
                 justify=tk.LEFT,
                 padx=80).pack(in_=self._frame, anchor=tk.N)

        for val, state in enumerate(self._game_states):
            tk.Radiobutton(self._root,
                           text=state,
                           indicatoron=0,
                           width=20,
                           padx=20,
                           variable=self._v,
                           command=self._PublishMusicBoxState,
                           value=val).pack(in_=self._frame, anchor=tk.N)

    def _PublishMusicBoxState(self):
        music_box_msg = std_msgs.msg.UInt8()
        music_box_msg.data = self._v.get()

        rospy.loginfo(music_box_msg)
        self._ros_node.music_box_state_pub.publish(music_box_msg)

    def _InitSubscribers(self):
        rospy.Subscriber("music_box_state", std_msgs.msg.UInt8,
                         self._MusicBoxStateCallBack)

    def _MusicBoxStateCallBack(self, msg_in):
        self._v.set(msg_in.data)
