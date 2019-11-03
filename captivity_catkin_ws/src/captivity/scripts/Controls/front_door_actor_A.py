#!/usr/bin/env python3

import rospy
import std_msgs.msg
from captivity.msg import GameState as GameStateMsg

import tkinter as tk

from Controls.door_actor_abstract import DoorActorAbstract


class FrontDoorActorA(DoorActorAbstract):

    def _InitFrame(self):
        self._frame.grid(row=0, column=0, padx=(10, 10), pady=(10, 10))

    def _InitLabel(self):
        button = tk.Radiobutton(self._root,
                                text="MONSTER",
                                indicatoron=0,
                                width=20,
                                padx=20,
                                variable=self._v,
                                command=self._PublishActorState,
                                value=3)
        button.pack(in_=self._frame, anchor=tk.N)
        self.radio_buttons["MONSTER"] = button

        self._name = "FRONT ACTOR A"

        self.label.configure(text=self._name)

        self.label.pack(in_=self._frame, anchor=tk.N)

    def _PublishActorState(self):
        actor_msg = std_msgs.msg.UInt8()
        actor_msg.data = self._v.get()

        rospy.loginfo(actor_msg)
        self._ros_node.front_door_actor_A_state_pub.publish(actor_msg)

    def _InitSubscribers(self):
        rospy.Subscriber("front_actor_A_state", std_msgs.msg.UInt8,
                         self._ActorStateCallBack)

    # def _PlayerLost(self):
    #     game_state_msg = GameStateMsg()
    #     game_state_msg.player1 = 0
    #     game_state_msg.player2 = 1
    #     game_state_msg.game_state = 2

    #     rospy.loginfo(game_state_msg)
    #     self._ros_node.game_state_pub.publish(game_state_msg)
