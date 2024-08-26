/*
Write C++ program to draw a given pattern. Use DDA line and Bresenham’s
circle drawing algorithm. Apply the concept of encapsulation.
*/

#include <iostream>
#include <graphics.h>
#include <math.h>

class Line {
public:
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = std::max(abs(dx), abs(dy));
        float x_inc = dx / (float)steps;
        float y_inc = dy / (float)steps;

        float x = x1;
        float y = y1;
        putpixel(round(x), round(y), WHITE);

        for (int i = 0; i < steps; i++) {
            x += x_inc;
            y += y_inc;
            putpixel(round(x), round(y), WHITE);
        }
    }
};

class Circle {
public:
    void drawCircle(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;
        drawCirclePoints(xc, yc, x, y);
        while (y >= x) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
            drawCirclePoints(xc, yc, x, y);
        }
    }

private:
    void drawCirclePoints(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Line line;
    Circle circle;

    // Draw the outer circle
    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int radius = 150;
    circle.drawCircle(xc, yc, radius);

    // Draw the inner circle
    int innerRadius = 70;
    circle.drawCircle(xc, yc, innerRadius);

    // Draw the triangle inside the outer circle
    int x1 = xc;
    int y1 = yc - radius;
    int x2 = xc - radius * sqrt(3) / 2;
    int y2 = yc + radius / 2;
    int x3 = xc + radius * sqrt(3) / 2;
    int y3 = yc + radius / 2;

    line.drawLine(x1, y1, x2, y2);
    line.drawLine(x2, y2, x3, y3);
    line.drawLine(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}
