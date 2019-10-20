#!/usr/bin/env python3

import rospy
from nexus_gui import NexusGui
from nexus_ros_node import NexusRosNode

import time

if __name__ == "__main__":
    try:
        node = NexusRosNode()

        gui = NexusGui(node)
        gui.Init()
        gui.Start()

    except rospy.ROSInterruptException:
        pass
