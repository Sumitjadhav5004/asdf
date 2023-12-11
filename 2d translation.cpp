/*
Write C++ program to draw 2-D object and perform following basic
transformations: 1. Scaling 2. Translation 3. Rotation. Apply the concept of
operator overloading.
*/
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Function prototypes
void translate(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty);
void scale(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy);
void arotate(int x1, int y1, int x2, int y2, int x3, int y3, float a);
void crotate(int x1, int y1, int x2, int y2, int x3, int y3, float a);
void display(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
    int x1, y1, x2, y2, x3, y3;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter the coordinates of the triangle (x1, y1, x2, y2, x3, y3): " << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    while (1) {
        int ch;
        cout << "Enter 1-T 2-S 3-AR 4-CR 0-Exit: " << endl;
        cin >> ch;

        if (ch == 1) {
            int tx, ty;
            cout << "Enter tx and ty: " << endl;
            cin >> tx >> ty;
            translate(x1, y1, x2, y2, x3, y3, tx, ty);
        } else if (ch == 2) {
            float sx, sy;
            cout << "Enter sx and sy: " << endl;
            cin >> sx >> sy;
            scale(x1, y1, x2, y2, x3, y3, sx, sy);
        } else if (ch == 3) {
            float a;
            cout << "Enter angle: " << endl;
            cin >> a;
            arotate(x1, y1, x2, y2, x3, y3, a);
        } else if (ch == 4) {
            float a;
            cout << "Enter angle: " << endl;
            cin >> a;
            crotate(x1, y1, x2, y2, x3, y3, a);
        } else if (ch == 0) {
            cout << "Exit." << endl;
            break;
        }
    }

    getch();
    closegraph();
    return 0;
}

void translate(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) {
    outtextxy(100, 100, "Before Translation : ");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Translation");
    display(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty);
}

void scale(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy) {
    outtextxy(100, 100, "Before scaling : ");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After scaling : ");
    display(x1 * sx, y1 * sy, x2 * sx, y2 * sy, x3 * sx, y3 * sy);
}

void arotate(int x1, int y1, int x2, int y2, int x3, int y3, float a) {
    a = a * (3.14 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before rotation : ");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After rotation : ");
    display((x1 * c - y1 * s), (x1 * s + y1 * c), (x2 * c - y2 * s), (x2 * s + y2 * c), (x3 * c - y3 * s), (x3 * s + y3 * c));
}

void crotate(int x1, int y1, int x2, int y2, int x3, int y3, float a) {
    a = a * (3.14 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before rotation : ");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After rotation : ");
    display((x1 * c + y1 * s), (-x1 * s + y1 * c), (x2 * c + y2 * s), (-x2 * s + y2 * c), (x3 * c + y3 * s), (-x3 * s + y3 * c));
}

void display(int x1, int y1, int x2, int y2, int x3, int y3) {
    int xmid = getmaxx() / 2;
    int ymid = getmaxy() / 2;

    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);

    line(x1 + xmid, y1 + ymid, x2 + xmid, y2 + ymid);
    line(x2 + xmid, y2 + ymid, x3 + xmid, y3 + ymid);
    line(x1 + xmid, y1 + ymid, x3 + xmid, y3 + ymid);
}
