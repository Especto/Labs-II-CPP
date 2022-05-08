#include <iostream>
#include <vector>
#include "Functions.h"
using namespace std;
#define M_PI 3.14159265358979323846


int main()
{
    vector <Circle> array;
    array = createObjects();
    output(array);
    findLargest(array);
}





