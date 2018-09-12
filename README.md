# QtThread01 -- simple threaded GUI example

This program should display a window with a circle that gradually moves
from left to right.  Two worker threads "fight" over the x location locx, with
one of the workers steadily "winning."  The purpose of this app is to demonstrate
a simple example of how threading might work to take advantage of multiple cpu cores.
This code was written by an amateur hobbyist coder, and should not be used as the
basis for any production systems without review by a professional developer.

One important thing to notice when running this several times is that the circle
does not always make it to the same ending position.  This is because the worker
threads are running unequal amounts of times as can be seen by the totaliterations
counter that displays when the workers complete.  The threads get varying levels of
cpu time whether because of operating system issues, or how Qt works, or for any other
reason.  This code does not account for these factors, and so it's an example of how
things can get out of sync with threads if they are not managed properly.

It should be noted that we are not killing the threads properly: closing the window
by clicking the X button on the window while shutdowncounter > 0 does
not send any cleanup signal or anything to the threads, so they do not end gracefully
and you will get "QThread: Destroyed while thread is still running" in app output.
Don't do it this way in production.

After closing the window before the worker threads finished a few times, Windows apparently
decided that this code is being sketchy with the heap, for awhile I got this message in
Application Output at runtime:

FTH: (10180): *** Fault tolerant heap shim applied to current process. This is usually due to previous crashes. ***

...just FYI.  I have no idea what the implications here might be for things like Windows Defender, or
any other such issues.  After I ran the code a number of times without stopping the window
before the worker threads finished, windows apparently decided to stop making this fault
tolerant heap shim thing happen, and I stopped seeing that message.

This code was written on Qt 5.11.1 on Windows 10.  It may run on OS X and Linux with
modifications but we haven't done that.

This code is copyright 2018 inhabited.systems, and is shared under the MIT license.
(See file MIT-License.txt)  This code is unsupported.