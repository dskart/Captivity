#!/usr/bin/env python3
import tkinter as tk
import tkinter.ttk

from Visualizer.current_game_state import CurrentGameState
from Visualizer.player_A import PlayerA
from Visualizer.player_B import PlayerB

from Visualizer.music_box import MusicBox


class NexusVisualizerGui:
    def __init__(self, ros_node):
        self._ros_node = ros_node

    def Init(self):
        self._root = tk.Tk()
        self._root.attributes('-type', 'dialog')

        self._app = MainWindow(self._root)

        self._player_A = PlayerA(self._app, self._ros_node)
        self._player_B = PlayerB(self._app, self._ros_node)

        self._music_box = MusicBox(self._app, self._ros_node)
        self._current_game_state = CurrentGameState(self._app, self._ros_node)

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
        self.master.title("NEXUS VISUALIZER")
        self.pack(fill=tk.BOTH, expand=1)
