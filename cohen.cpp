#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int X1, Y1, X2, Y2;
    cout << "Enter the clipping window dimensions : " << endl;
    cin >> X1 >> Y1 >> X2 >> Y2;

    int x1, x2, y1, y2;
    cout << "Enter the line coordinates : " << endl;
    cin >> x1 >> y1 >> x2 >> y2;

    int op[2][4];

    // Compute outcodes for both endpoints
    op[0][0] = (y1 < Y1) ? 1 : 0;
    op[0][1] = (y1 > Y2) ? 1 : 0;
    op[0][2] = (x1 > X2) ? 1 : 0;
    op[0][3] = (x1 < X1) ? 1 : 0;

    op[1][0] = (y2 < Y1) ? 1 : 0;
    op[1][1] = (y2 > Y2) ? 1 : 0;
    op[1][2] = (x2 > X2) ? 1 : 0;
    op[1][3] = (x2 < X1) ? 1 : 0;

    cout << op[0][0] << op[0][1] << op[0][2] << op[0][3] << endl;
    cout << op[1][0] << op[1][1] << op[1][2] << op[1][3] << endl;

    initgraph(&gd, &gm, NULL);
    outtextxy(100, 100, "Before clipping : ");
    rectangle(X1, Y1, X2, Y2);
    line(x1, y1, x2, y2);
    delay(10000);
    cleardevice();

    float m = static_cast<float>(y2 - y1) / (x2 - x1);

    if (op[0][0] == 0 && op[0][1] == 0 && op[0][2] == 0 && op[0][3] == 0 && op[1][0] == 0 && op[1][1] == 0 && op[1][2] == 0 && op[1][3] == 0) {
        // Line is completely inside the window
        line(x1, y1, x2, y2);
    } else if ((op[0][0] && op[1][0]) || (op[0][1] && op[1][1]) || (op[0][2] && op[1][2]) || (op[0][3] && op[1][3])) {
        // Line is completely outside the window
        x1 = x2 = y1 = y2 = 0;
    } else {
        // Line needs to be clipped
        if (op[0][0] == 1) {
            x1 = x1 + static_cast<int>((Y1 - y1) / m);
            y1 = Y1;
        }
        if (op[1][0] == 1) {
            x2 = x2 + static_cast<int>((Y1 - y2) / m);
            y2 = Y1;
        }
        if (op[0][1] == 1) {
            x1 = x1 + static_cast<int>((Y2 - y1) / m);
            y1 = Y2;
        }
        if (op[1][1] == 1) {
            x2 = x2 + static_cast<int>((Y2 - y2) / m);
            y2 = Y2;
        }
        if (op[0][2] == 1) {
            y1 = y1 + static_cast<int>(m * (X2 - x1));
            x1 = X2;
        }
        if (op[1][2] == 1) {
            y2 = y2 + static_cast<int>(m * (X2 - x2));
            x2 = X2;
        }
        if (op[0][3] == 1) {
            y1 = y1 + static_cast<int>(m * (X1 - x1));
            x1 = X1;
        }
        if (op[1][3] == 1) {
            y2 = y2 + static_cast<int>(m * (X1 - x2));
            x2 = X1;
        }

        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();

    return 0;
}
