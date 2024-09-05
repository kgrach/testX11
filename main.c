#include <stdio.h>
#include <X11/Xlib.h>

int main()
{
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);

    /* uncomment if geometry is needed
    XWindowAttributes attr;
    XGetWindowAttributes(display, root, &attr);
    int width = attr.width;
    int height = attr.height;*/

    XImage *image = XGetImage(display, root, 0, 0 , 100, 100, AllPlanes, ZPixmap);

    if (image) {
        printf("%d %d (%p)\n", image->width, image->height, image->data);
        return 0;
    } else {
        printf("error");
        return -1;
    }
}
