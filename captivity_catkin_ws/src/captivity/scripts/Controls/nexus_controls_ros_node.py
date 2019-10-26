#!/usr/bin/env python3

import rospy
from captivity.msg import GameState
from captivity.msg import Num
from std_msgs.msg import UInt8


class NexusControlsRosNode:
    def __init__(self):
        self._hello_num = 0
        self._InitPublisherTopics()
        rospy.init_node('nexus_controls', anonymous=True)
        self._rate = rospy.Rate(10)  # 10hzs

    def Loop(self):
        if not rospy.is_shutdown():
            self._rate.sleep()
        else:
            exit()

    def _InitPublisherTopics(self):
        self.game_state_pub = rospy.Publisher(
            'game_state', GameState, queue_size=10)

        self.front_door_actor_A_state_pub = rospy.Publisher(
            'front_actor_A_state', UInt8, queue_size=10)
        self.front_door_actor_B_state_pub = rospy.Publisher(
            'front_actor_B_state', UInt8, queue_size=10)

        self.back_door_actor_A_state_pub = rospy.Publisher(
            'back_actor_A_state', UInt8, queue_size=10)
        self.back_door_actor_B_state_pub = rospy.Publisher(
            'back_actor_B_state', UInt8, queue_size=10)

        self.music_box_A_state_pub = rospy.Publisher(
            'music_box_A_state', UInt8, queue_size=10)

        self.music_box_B_state_pub = rospy.Publisher(
            'music_box_B_state', UInt8, queue_size=10)
