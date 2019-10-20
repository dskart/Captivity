#!/usr/bin/env python3

import rospy
from captivity.msg import GameState
from captivity.msg import Num


class NexusRosNode:
    def __init__(self):
        self._hello_num = 0
        self._InitPublisherTopics()
        rospy.init_node('Nexus', anonymous=True)
        self._rate = rospy.Rate(10)  # 10hzs

    def Loop(self):
        if not rospy.is_shutdown():
            self._rate.sleep()
        else:
            exit()

    def _InitPublisherTopics(self):
        self.game_state_pub = rospy.Publisher(
            'game_state', GameState, queue_size=10)
