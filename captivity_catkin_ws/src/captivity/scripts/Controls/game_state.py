#!/usr/bin/env python3

import rospy
from captivity.msg import GameState as GameStateMsg
import tkinter as tk


class GameState:
    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._frame.grid(row=0, column=1, padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root

        self._InitWidgets()

    def _InitWidgets(self):
        self._v = tk.IntVar()

        self._game_states = [
            ("IDLE", 0),
            ("RESET", 1),
            ("START", 2),
            ("END", 3),
        ]

        tk.Label(self._root,
                 text="""GAME STATE""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

        for val, state in enumerate(self._game_states):
            tk.Radiobutton(self._root,
                           text=state,
                           indicatoron=0,
                           width=20,
                           padx=20,
                           variable=self._v,
                           command=self._PublishGameState,
                           value=val).pack(in_=self._frame, anchor=tk.N)

    def _PublishGameState(self):
        game_state_msg = GameStateMsg()
        game_state_msg.player1 = 0
        game_state_msg.player2 = 0
        game_state_msg.game_state = self._v.get()

        rospy.loginfo(game_state_msg)
        self._ros_node.game_state_pub.publish(game_state_msg)
