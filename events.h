//
// Created by jaakko on 9.4.2020.
//

#ifndef WM_EVENTS_H
#define WM_EVENTS_H

#include <X11/Xlib.h>

void wmKeyPress(XEvent event);
void wmButtonPress(XEvent event);
void wmEnterNotify(XEvent event);
void wmExpose(XEvent event);
void wmConfigureNotify(XEvent event);
void wmConfigureRequest(XEvent event);
void wmMapRequest(XEvent event);
void wmUnmapNotify(XEvent event);
void wmClientMessage(XEvent event);

extern void (*handler[LASTEvent])(XEvent);

#endif //WM_EVENTS_H
