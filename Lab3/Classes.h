#pragma once
#include <iostream>
using namespace std;
#define M_PI 3.14159265358979323846

class Circle {
    int x, y, R;
    double Ar;
public:
    void getX() { cout << "\tX: " << x << "\n"; };
    void getY() { cout << "\tY: " << y << "\n"; };
    void getR() { cout << "\tRadius: " << R << "\n"; };
    void getArea() { cout << "\tArea of circle: " << Ar; }
    void setXY(int xx, int yy) { x = xx; y = yy; };
    void setR(int radius) { R = radius; };
    double Area() { Ar = R * R * M_PI; return Ar; }

};
