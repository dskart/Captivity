#!/usr/bin/env python3
import tkinter as tk

from game_state_indicator import GameStateIndicator


class NexusGui:
    def __init__(self, ros_node):
        self._ros_node = ros_node

    def Init(self):
        self._root = tk.Tk()
        self._root.attributes('-type', 'dialog')

        self._root.geometry("800x600")
        self._app = MainWindow(self._root)
        self._game_state_indicator = GameStateIndicator(
            self._app, self._ros_node)

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
        self.master.title("NEXUS FOR CAPTIVITY")
        self.pack(fill=tk.BOTH, expand=1)
