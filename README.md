# QtThread01 -- simple threaded GUI example
This program should display a window with a small circle that gradually moves
from left to right.  Two worker threads "fight" over the x location locx, with
one of the workers steadily "winning."  The purpose of this app is to demonstrate
a simple example of how threading can work to take advantage of multiple cpu cores.

It should be noted that we are not killing the threads properly: closing the window
by clicking the X button on the window while shutdowncouner < shutdowncountmax does
not send any cleanup signal or anything to the threads, so they do not end gracefully
and you will get "QThread: Destroyed while thread is still running" in app output.
Don't do it this way in production.

This app is copyright 2018 inhabited.systems all rights reserved.