#!/usr/bin/env python3

import rospy
from captivity.msg import GameState as GameStateMsg
from captivity.msg import Num
from std_msgs.msg import UInt8

# from Visualizer.current_game_state import CurrentGameStateCallback


class NexusVisualizerRosNode:
    def __init__(self):
        # self._InitPublisherTopics()
        rospy.init_node('nexus_visualizer', anonymous=True)
        self._rate = rospy.Rate(10)  # 10hzs

    def Loop(self):
        if not rospy.is_shutdown():
            self._rate.sleep()
        else:
            exit()

    def _InitPublisherTopics(self):
        pass
