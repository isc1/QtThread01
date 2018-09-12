# QtThread01 -- simple Qthread example with graphics

![QtThread01](/QtThread01.png)

This program should display a window with a circle that gradually moves
from left to right.  Two worker threads "fight" over the x location **locx**, with
one of the workers steadily "winning."  A box is drawn near the scene center to help
see where the circle ends up when the worker threads are done.

The purpose of this app is to demonstrate a simple example of how threading might
work to take advantage of multiple cpu cores.  This code was written by a hobbyist coder,
and should not be used as the basis for any production systems without review by a
professional developer. (I don't think anyone would do that, I'm just trying
to provide a warning here that this is totally amateur level code, so use at your own risk.)

It's also important to understand that the worker threads *are not taking turns* but rather
are running as many times as they can (and therefore modifying **locx** as many times as they
can) before the mutex lock happens from the other thread.

This is the reason the circle ends up at different positions every runtime.  This happens
because the worker threads are running unequal numbers of times as can be seen by the
**totaliterations** counter that qDebug() displays when the workers complete.  The threads
get varying levels of cpu time whether because of operating system issues, or how Qt works,
or for some other reasons.

This code does not account for these factors, and so it's an example
of how things can get out of sync with threads if they are not managed properly.  Sometimes
the variability between how many times the worker threads run is quite large, and the circle
either barely moves or moves much farther than the "target" square, depending on which
worker got more runtime.  This is one example of why threads are kind of intimidating to me,
personally. :-)  It's easy for weird things to happen that do not have obvious causes.  You can
uncomment the **usleep(1)** functions in the workers to see more.

It should be noted that we are not killing the threads properly: closing the window
by clicking the X button on the window while **shutdowncounter** > 0 (i.e. before the
worker threads finish running and exit) does not send any cleanup signal or anything to
the threads, so they do not end gracefully and you will get:

_QThread: Destroyed while thread is still running_

...in app output.  I need to fix this.  Don't do it this way in production.  This code also uses
extern globals, and doesn't use getters/setters, and commits other such misdemeanors, fyi.

After closing the window before the worker threads finished a few times, Windows apparently
decided that this code is being sketchy with the heap; for awhile I got this message in
Application Output at runtime:

_FTH: (10180): *** Fault tolerant heap shim applied to current process. This is usually due to previous crashes. ***_

...just FYI.  I have no idea what the implications here might be for things like Windows Defender, or
any other such issues.  After I ran the code a number of times without stopping the window
before the worker threads finished, windows apparently decided to stop making this fault
tolerant heap shim thing happen, and I stopped seeing that message.

*This code was written on Qt 5.11.1 on Windows 10.  It may run on OS X and Linux with modifications but we haven't done that.*

*This code is copyright 2018 inhabited.systems, and is shared under the MIT license. (See file MIT-License.txt)  This code is unsupported.*