/*Write C++ program to draw a concave polygon and fill it with desired color
using scan fill algorithm*/
#include <graphics.h>
#include <iostream>
using namespace std;

void floodfill(int x, int y, int o, int n) {
    if (getpixel(x, y) == o) {
        putpixel(x, y, n);
        floodfill(x + 1, y, o, n);
        floodfill(x - 1, y, o, n);
        floodfill(x, y + 1, o, n);
        floodfill(x, y - 1, o, n);
        floodfill(x + 1, y - 1, o, n);
        floodfill(x + 1, y + 1, o, n);
        floodfill(x - 1, y - 1, o, n);
        floodfill(x - 1, y + 1, o, n);
    }
}

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    line(100, 100, 50, 400);
    line(100, 100, 150, 400);
    line(50, 400, 100, 200);
    line(150, 200, 100, 200);

    floodfill(100, 150, 0, 7);

    getch();
    closegraph();

    return 0;
}
