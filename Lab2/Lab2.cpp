#include "header.h"
using namespace std;


int main()
{
    string inPath, outPath;
    Technic a;
    cout << "Enter file path 1: ";
    getline(cin, inPath);
    cout << "Enter file path 2: ";
    getline(cin, outPath);
    createFile(inPath);
    enterFile(inPath);
    outExpired(inPath, outPath);
    cout << "\nList of Techniques: \n";
    showFile(inPath);
    cout << "\nList of expired Techniques: \n";
    showFile(outPath);
    return 0;
}

