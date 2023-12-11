//bresenham outer circle
/////outer circle
#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

class Line {
public:
    void drawLine(int x1, int y1, int x2, int y2) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        float xIncrement = dx / steps;
        float yIncrement = dy / steps;

        float x = x1;
        float y = y1;

        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xIncrement;
            y += yIncrement;
        }
    }
};

class Circle {
public:
    void drawCircle(int centerX, int centerY, int radius) {
        int x = 0, y = radius;
        int d = 3 - 2 * radius;

        while (x <= y) {
            drawSymmetricPoints(centerX, centerY, x, y);
            x++;

            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }

            drawSymmetricPoints(centerX, centerY, x, y);
        }
    }

private:
    void drawSymmetricPoints(int centerX, int centerY, int x, int y) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Line line;
    Circle circle;

    // Outer Circle
    circle.drawCircle(200, 200, 50);

    // Triangle inside the circle
    line.drawLine(200, 150, 250, 250);
    line.drawLine(250, 250, 150, 250);
    line.drawLine(150, 250, 200, 150);

    // Inner Circle inside the triangle
    circle.drawCircle(200, 200, 25);

    getch();
    closegraph();

    return 0;
}





//bresenham outer rectangle
/*
5. A) Write a C++ program for drawing a
following pattern(diamond in rectangle)
*/
CODE:
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int sign(int x)
{
if(x<0)
return -1;
else if(x>0)
return 1;
else
return 0;
}
void bline(int x1,int y1,int x2,int y2,int col)
{
int dx,dy,e,x,y,i=1;
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
e=2*dy-dx;
while(i<=dx)
{
while(e>=0)
{
y++;
e=e-2*dx;
}
x++;

e=e+2*dy;
putpixel(x,y,col);
i++;
}
}
void ddaline(int x1,int y1,int x2,int y2,int
col)
{
int x,y,len,i;
float dx,dy;
if(x1==x2 && y1==y2)
putpixel(x1,y1,col);
else
{
dx=x2-x1;
dy=y2-y1;
if(dx>dy)
len=dx;
else
len=dy;
dx=(x2-x1)/len;
dy=(y2-y1)/len;
x=x1+0.5*sign(dx);
y=y1+0.5*sign(dy);
i=1;
while(i<len)
{
putpixel(x,y,col);
x=x+dx;
y=y+dy;
i++;
}
}
}
int main()
{

int ch,col,x1,x2,y1,y2;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(WHITE);
ddaline(50,50,50,200,2); //left vert
ddaline(50,50,350,50,4); //up horizontal
ddaline(350,50,350,200,6); //right vert
ddaline(50,200,350,200,7); //down horizontal
ddaline(200,50,50,125,9); //diamond up left
bline(50,125,200,200,12); //diamond left,down
ddaline(350,125,200,200,14);//diamond down,right
bline(200,50,350,125,3); //diamond right,up
ddaline(275,87,275,163,4);//in right
ddaline(125,87,275,87,5);//in up
ddaline(125,87,125,163,6);//in left
ddaline(125,163,275,163,2);//in down
getch();
closegraph();
return 0;
}

