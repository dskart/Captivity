#!/usr/bin/env python3

import rospy
import std_msgs.msg
from captivity.msg import GameState as GameStateMsg

import tkinter as tk

from Controls.door_actor_abstract import DoorActorAbstract


class BackDoorActorB(DoorActorAbstract):

    def _InitFrame(self):
        self._frame.grid(row=1, column=1, padx=(10, 10), pady=(10, 10))

    def _InitLabel(self):
        self._name = "BACK ACTOR B"

        self.label.configure(text=self._name)

        self.label.pack(in_=self._frame, anchor=tk.N)

    def _PublishActorState(self):
        actor_msg = std_msgs.msg.UInt8()
        actor_msg.data = self._v.get()

        rospy.loginfo(actor_msg)
        self._ros_node.back_door_actor_B_state_pub.publish(actor_msg)

    def _InitSubscribers(self):
        rospy.Subscriber("back_actor_B_state", std_msgs.msg.UInt8,
                         self._ActorStateCallBack)

        rospy.Subscriber("iris_B_state", std_msgs.msg.UInt8,
                         self._DoorEventCallBack)

    # def _PlayerLost(self):
    #     game_state_msg = GameStateMsg()
    #     game_state_msg.player1 = 0
    #     game_state_msg.player2 = 1
    #     game_state_msg.game_state = 2

    #     rospy.loginfo(game_state_msg)
    #     self._ros_node.game_state_pub.publish(game_state_msg)
