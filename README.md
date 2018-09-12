# QtThread01 -- simple threaded GUI example
This program should display a window with a circle that gradually moves
from left to right.  Two worker threads "fight" over the x location locx, with
one of the workers steadily "winning."  The purpose of this app is to demonstrate
a simple example of how threading can work to take advantage of multiple cpu cores.

One important thing to notice when running this several times is that the circle
does not always make it to the same ending position.  This is because the worker
threads are not running the same amount of times.  This is an illustration of how
the code has to account for the threads getting varying levels of cpu time whether
because of operating system issues, or how Qt works, or any other reason.  This
code does not account for these factors, and so it's a good example of how things
can get out of sync with threads if they are not managed properly.

It should be noted that we are not killing the threads properly: closing the window
by clicking the X button on the window while shutdowncouner < shutdowncountmax does
not send any cleanup signal or anything to the threads, so they do not end gracefully
and you will get "QThread: Destroyed while thread is still running" in app output.
Don't do it this way in production.

This app is copyright 2018 inhabited.systems all rights reserved.