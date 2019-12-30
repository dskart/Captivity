
#!/usr/bin/env python3

import rospy
import std_msgs
from captivity.msg import GameState as GameStateMsg
import tkinter as tk


class KillPlayers:
    def __init__(self, root, ros_node):
        self._frame = tk.Frame(root)
        self._frame.grid(columnspan=2, padx=(10, 10), pady=(10, 10))

        self._ros_node = ros_node
        self._root = root

        self._player_A_state = 1
        self._player_B_state = 1

        self._InitWidgets()
        self._InitSubscribers()

    def _InitWidgets(self):
        self._v = tk.IntVar()

        tk.Label(self._root,
                 text="""KILL PLAYERS""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

        self._player_A = tk.Button(self._root,
                                   text="PLAYER A",
                                   width=20,
                                   padx=20,
                                   command=self._KillPlayerA)

        self._player_A.pack(in_=self._frame, anchor=tk.N)

        self._player_B = tk.Button(self._root,
                                   text="PLAYER B",
                                   width=20,
                                   padx=20,
                                   command=self._KillPlayerB)

        self._player_B.pack(in_=self._frame, anchor=tk.N)

    def _KillPlayerA(self):
        game_state_msg = GameStateMsg()
        game_state_msg.player1 = 0
        game_state_msg.player2 = self._player_B_state
        game_state_msg.game_state = 2

        rospy.loginfo(game_state_msg)
        self._ros_node.game_state_pub.publish(game_state_msg)

    def _KillPlayerB(self):
        game_state_msg = GameStateMsg()
        game_state_msg.player1 = self._player_A_state
        game_state_msg.player2 = 0
        game_state_msg.game_state = 2

        rospy.loginfo(game_state_msg)
        self._ros_node.game_state_pub.publish(game_state_msg)

    def _InitSubscribers(self):
        rospy.Subscriber("game_state", GameStateMsg,
                         self._UpdatePlayerState)

    def _UpdatePlayerState(self, msg_in):
        self._player_A_state = msg_in.player1
        self._player_B_state = msg_in.player2
