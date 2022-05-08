#include "Functions.h"
#include <iostream>
#include <vector>
using namespace std;


vector <Circle> createObjects() {
    vector <Circle> array;
    char ans;
    bool flag = true;
    while (flag) {
        array.push_back(input());
        cout << "Countinue entering?(y/n)"; cin >> ans; cin.ignore();
        if (ans != 'y') {
            flag = false;
        }
    }
    return array;
}

Circle input() {
    Circle circle;
    int x, y, R;
    cout << "Enter X: "; cin >> x;
    cout << "Enter Y: "; cin >> y;
    cout << "Enter radius: "; cin >> R;
    circle.setXY(x, y);
    circle.setR(R);
    return circle;
}


void output(vector <Circle> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << "\nCircle "; cout << i + 1; cout << ":\n";
        array[i].getX();
        array[i].getY();
        array[i].getR();
    }
}

void findLargest(vector <Circle> array) {
    Circle largestCircle = array[0];
    for (int i = 0; i < array.size(); i++) {
        if (array[i].Area() > largestCircle.Area()) {
            largestCircle = array[i];
        }
    }
    cout << "\nThe largest circle is located at \n";
    largestCircle.getX();
    largestCircle.getY();
    largestCircle.getR();
    largestCircle.getArea();

}