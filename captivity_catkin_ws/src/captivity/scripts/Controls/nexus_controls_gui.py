#!/usr/bin/env python3
import tkinter as tk

from Controls.game_state import GameState
from Controls.front_door_actor_A import FrontDoorActorA
from Controls.front_door_actor_B import FrontDoorActorB
from Controls.back_door_actor_A import BackDoorActorA
from Controls.back_door_actor_B import BackDoorActorB
from Controls.music_box_A import MusicBoxA
from Controls.music_box_B import MusicBoxB
from Controls.life_switch import LifeSwitch
from Controls.kill_players import KillPlayers


class NexusControlsGui:
    def __init__(self, ros_node):
        self._ros_node = ros_node

    def Init(self):
        self._root = tk.Tk()
        self._root.attributes('-type', 'dialog')

        # self._root.geometry("800x600")
        self._app = MainWindow(self._root)

        self._front_door_actor_A = FrontDoorActorA(self._app, self._ros_node)
        self._front_door_actor_B = FrontDoorActorB(self._app, self._ros_node)

        self._back_door_actor_A = BackDoorActorA(self._app, self._ros_node)
        self._back_door_actor_B = BackDoorActorB(self._app, self._ros_node)

        # self._music_box_A = MusicBoxA(self._app, self._ros_node)
        # self._music_box_B = MusicBoxB(self._app, self._ros_node)

        self._music_box_A = MusicBoxA(self._app, self._ros_node)
        self._game_state = GameState(self._app, self._ros_node)
        self._life_switch = LifeSwitch(self._app, self._ros_node)
        self._kill_players = KillPlayers(self._app, self._ros_node)

    def Start(self):
        self._root.after(1, self._LoopRosNode)
        self._root.mainloop()

    def _LoopRosNode(self):
        self._ros_node.Loop()
        self._root.after(1, self._LoopRosNode)


class MainWindow(tk.Frame):

    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.master = master
        self._InitWindow()

    def _InitWindow(self):
        self.master.title("NEXUS CONTROL")
        self.pack(fill=tk.BOTH, expand=1)
