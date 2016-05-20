#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    Display *d;
    Window w;
    XEvent e;
    int s;
    

    /* open connection with the server */
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);

    /* create window */
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 1280, 720, 1,
            BlackPixel(d, s), WhitePixel(d, s));

    /* select kind of events we
     * are interested in */
    XSelectInput(d, w, ExposureMask | KeyPressMask);

    /* map (show) the window
     * */
    XMapWindow(d, w);

    /* event loop */
    while (1) {
        XNextEvent(d, &e);
        /* draw or
         * redraw
         * the
         * window
         * */
        if (e.type == Expose) {
            /*XFillRectangle(d, w, DefaultGC(d, s), 0, 0, 500, 720);*/
            FILE *fp;
            char line[255];
            fp = fopen(".env", "r");
            int index = 1;
            while(fgets(line, 255, (FILE*)fp)) {
                XDrawString(d, w, DefaultGC(d, s), 50, index * 50, line, strlen(line));
                index ++;
            }
            fclose(fp);
        }
        /* exit
         * on
         * key
         * press
         * */
        /*if (e.type == KeyPress)*/
        /*if (e.type == KeyPress)*/
            /*break;*/
    }

    /* close connection
     * to server */
    XCloseDisplay(d);

    return 0;
}
