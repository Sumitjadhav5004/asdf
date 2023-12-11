#include <iostream>
#include <graphics.h>
#include <conio.h>

class Person {
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Man : public Person {
public:
    void draw() override {
        circle(300, 300, 20);   // Head
        line(300, 320, 300, 360);  // Body
        line(300, 340, 280, 320);  // Left arm
        line(300, 340, 320, 320);  // Right arm
        line(300, 360, 280, 380);  // Left leg
        line(300, 360, 320, 380);  // Right leg
    }
};

class Umbrella : public Person {
public:
    void draw() override {
        arc(300, 290, 0, 180, 40);  // Umbrella top
        line(300, 290, 300, 360);   // Umbrella handle
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Person* manWithUmbrella = new Man();
    manWithUmbrella->draw();

    Person* umbrella = new Umbrella();
    umbrella->draw();

    getch();
    closegraph();
    return 0;
}
