//
// Created by jaakko on 10.4.2020.
//

#include <X11/Xlib.h>

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#include "api.h"
#include "instance.h"

void closeActiveWindow(Arg a) {
    wmWindow* activeWindow = wmWorkspaces[wmActiveWorkspace].activeWindow;
    if (activeWindow) {
        wmRequestCloseWindow(activeWindow);
    }
}

void focus(Arg a) {
    wmWorkspace* workspace = &wmWorkspaces[wmActiveWorkspace];
    wmWindow* activeWindow = workspace->activeWindow;
    if (activeWindow && workspace->fullscreen == NULL) {
        wmWindow* focus =
                a.i == 1
                ? wmNextVisibleWindow(wmActiveWorkspace)
                : wmPreviousVisibleWindow(wmActiveWorkspace);
        if (focus) {
            wmFocusWindow(focus);
        }
    }
}

void openApplication(Arg a) {
    if (fork() == 0) {
        setsid();
        execvp(((const char**)a.v)[0], (char**)a.v);
        exit(EXIT_SUCCESS);
    }
}

void quit(Arg a) {
    wmRunning = False;
    wmExitCode = a.i;
}

void selectWorkspace(Arg a) {
    if (a.i != wmActiveWorkspace) {
        wmSelectWorkspace(a.i);
    }
}

void moveToWorkspace(Arg a) {
    wmMoveActiveWindow(a.i);
}

void toggleToWorkspace(Arg a) {
    wmToggleActiveWindow(a.i);
}

void lowerSplit(Arg a) {
    wmLowerSplit(a.i);
}

void raiseSplit(Arg a) {
    wmRaiseSplit(a.i);
}

void clearSplitHints(Arg a) {
    wmWorkspaces[wmActiveWorkspace].showSplitBorder = 0;
    wmUpdateBorders();
}

void moveLeftEdgeHorizontally(Arg a) {
    wmMoveLeftEdgeHorizontally(a.i);
}

void moveRightEdgeHorizontally(Arg a) {
    wmMoveRightEdgeHorizontally(a.i);
}

void moveUpperEdgeVertically(Arg a) {
    wmMoveUpperEdgeVertically(a.i);
}

void moveLowerEdgeVertically(Arg a) {
    wmMoveLowerEdgeVertically(a.i);
}

void moveNode(Arg a) {
    wmMoveNode(a.i);
}

void toggleFullscreen(Arg a) {
    wmToggleFullscreen();
}
