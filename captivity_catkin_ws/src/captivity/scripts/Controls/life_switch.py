#!/usr/bin/env python3

import rospy
import std_msgs
import tkinter as tk


class LifeSwitch:
    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._frame.grid(columnspan=2, padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root

        self._InitSubscribers()
        self._InitWidgets()

    def _InitWidgets(self):
        self._v = tk.IntVar()

        self._game_states = [
            ("PLAYER_A", 0),
            ("PLAYER_B", 1),
        ]

        tk.Label(self._root,
                 text="""LIFE SWITCH""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

        for val, state in enumerate(self._game_states):
            tk.Radiobutton(self._root,
                           text=state,
                           indicatoron=0,
                           width=20,
                           padx=20,
                           variable=self._v,
                           command=self._PublishLifeSwitch,
                           value=val).pack(in_=self._frame, anchor=tk.N)

    def _PublishLifeSwitch(self):
        life_switch_msg = std_msgs.msg.UInt8()
        life_switch_msg.data = self._v.get()

        rospy.loginfo(life_switch_msg)
        self._ros_node.life_switch_state_pub.publish(life_switch_msg)

    def _InitSubscribers(self):
        rospy.Subscriber("life_switch_state", std_msgs.msg.UInt8,
                         self._LifeSwitchCallBack)

    def _LifeSwitchCallBack(self, msg_in):
        self._v.set(msg_in.data)
