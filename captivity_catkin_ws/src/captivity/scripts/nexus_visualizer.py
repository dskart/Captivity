#!/usr/bin/env python3

import rospy
from Visualizer.nexus_visualizer_gui import NexusVisualizerGui
from Visualizer.nexus_visualizer_ros_node import NexusVisualizerRosNode


import time

if __name__ == "__main__":
    try:
        node = NexusVisualizerRosNode()

        gui = NexusVisualizerGui(node)
        gui.Init()
        gui.Start()

    except rospy.ROSInterruptException:
        pass
