/*
Write C++ program to draw a given pattern. Use DDA line and Bresenham’s
circle drawing algorithm. Apply the concept of encapsulation.
*/
#include <graphics.h> // Include graphics header file
#include <iostream>
using namespace std;

// Class for DDA line drawing algorithm
class DDALine {
public:
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float xIncrement = dx / (float) steps;
        float yIncrement = dy / (float) steps;
        float x = x1;
        float y = y1;
        for (int i = 0; i <= steps; i++) {
            putpixel(x, y, WHITE);
            x += xIncrement;
            y += yIncrement;
        }
    }
};

// Class for Bresenham's circle drawing algorithm
class BresenhamsCircle {
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
    initgraph(&gd, &gm, nullptr); // Initialize graphics mode

    DDALine line;
    BresenhamsCircle circle;

    // Draw rectangle border
    line.drawLine(100, 100, 400, 100);
    line.drawLine(400, 100, 400, 300);
    line.drawLine(400, 300, 100, 300);
    line.drawLine(100, 300, 100, 100);

    // Draw diagonals in rectangle
    line.drawLine(100, 100, 400, 300);
    line.drawLine(400, 100, 100, 300);

    // Draw tangents to circle
    line.drawLine(250, 150, 250, 50);
    line.drawLine(150, 150, 150, 50);

    // Draw circle in center
    circle.drawCircle(250, 150, 50);

    getch();
    closegraph();

    return 0;
}
