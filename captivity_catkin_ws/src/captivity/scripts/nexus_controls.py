#!/usr/bin/env python3

import rospy
from Controls.nexus_controls_gui import NexusControlsGui
from Controls.nexus_controls_ros_node import NexusControlsRosNode

import time

if __name__ == "__main__":
    try:
        node = NexusControlsRosNode()

        gui = NexusControlsGui(node)
        gui.Init()
        gui.Start()

    except rospy.ROSInterruptException:
        pass
