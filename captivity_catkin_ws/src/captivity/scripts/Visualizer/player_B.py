#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32, UInt8
import tkinter as tk
import time

from Visualizer.player_abstract import PlayerAbstract


class PlayerB(PlayerAbstract):
    _monster_out = 0

    def _InitFrame(self):
        self._frame.grid(row=0, column=1, padx=(10, 10), pady=(10, 10))

    def _InitLabel(self):
        tk.Label(self._root,
                 text="""PLAYER B""",
                 justify=tk.CENTER).pack(in_=self._frame, anchor=tk.N)

    def _InitWidgets(self):
        self._canvas_width = 120
        self._canvas_height = 40
        self._life_canvas = tk.Canvas(self._root,
                                      width=self._canvas_width,
                                      height=self._canvas_height)
        self._life_canvas.pack(in_=self._frame, anchor=tk.N)

        self._life_rect = self._life_canvas.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="white")

        self._current_life = self._life_canvas.create_text(self._canvas_width / 2,
                                                           self._canvas_height / 2,
                                                           text="Null")

        self._front_door_light = tk.Canvas(self._root,
                                           width=self._canvas_width,
                                           height=self._canvas_height)
        self._front_door_light.pack(in_=self._frame, anchor=tk.N)

        self._front_door_light_rect = self._front_door_light.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="green")

        self._front_door_light.create_text(self._canvas_width / 2,
                                           self._canvas_height / 2,
                                           text="FRONT DOOR LIGHT")

        self._iris_lock = tk.Canvas(self._root,
                                    width=self._canvas_width,
                                    height=self._canvas_height)
        self._iris_lock.pack(in_=self._frame, anchor=tk.N)

        self._iris_lock_rect = self._iris_lock.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="green")

        self._iris_lock.create_text(self._canvas_width / 2,
                                    self._canvas_height / 2,
                                    text="IRIS_LOCK")

        self._front_door = tk.Canvas(self._root,
                                     width=self._canvas_width,
                                     height=self._canvas_height)
        self._front_door.pack(in_=self._frame, anchor=tk.N)

        self._front_door_rect = self._front_door.create_rectangle(
            0, 0, self._canvas_width, self._canvas_height, fill="green")

        self._front_door.create_text(self._canvas_width / 2,
                                     self._canvas_height / 2,
                                     text="FRONT DOOR")

    def _InitSubscribers(self):
        rospy.Subscriber("player_B_health", Int32,
                         self._PlayerHealthStateCallback)
        rospy.Subscriber("front_door_B_light", UInt8, self._FrontLightCallBack)
        rospy.Subscriber("iris_B_state", UInt8, self._IrisStateCallBack)
        rospy.Subscriber("front_door_B_state", UInt8, self._FrontDoorCallBack)

    def _PlayerHealthStateCallback(self, msg_in):
        new_health = msg_in.data
        self._life_canvas.itemconfig(self._current_life, text=str(new_health))

    def _FrontLightCallBack(self, msg_in):
        new_light_state = msg_in.data

        if new_light_state:
            self._front_door_light.itemconfig(
                self._front_door_light_rect, fill="red")
        else:
            self._front_door_light.itemconfig(
                self._front_door_light_rect, fill="green")

    def _IrisStateCallBack(self, msg_in):
        rospy.loginfo(msg_in.data)
        new_iris_state = msg_in.data

        if new_iris_state:
            self._iris_lock.itemconfig(
                self._iris_lock_rect, fill="green")
        else:
            self._iris_lock.itemconfig(
                self._iris_lock_rect, fill="red")

    def _FrontDoorCallBack(self, msg_in):
        rospy.loginfo(msg_in.data)
        new_front_door_state = msg_in.data

        if new_front_door_state:
            self._front_door.itemconfig(
                self._front_door_rect, fill="green")
        else:
            self._front_door.itemconfig(
                self._front_door_rect, fill="red")
