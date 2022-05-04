#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Header.h"
using namespace std;

void createFile(string path) {
    char a;
    cout << "Enter 'a' to add information or enter 'n' to create new file: "; cin >> a; cin.ignore();
    if (a == 'a') {
        ofstream File(path, ios::app);
        
    }
    else {
        ofstream File(path, ios::trunc);
    }
}
bool showFile(string path) {
    Technic a;
    ifstream File(path, ios::binary );
    while (File.read((char*)&a, sizeof(Technic))) {
        cout << "Name: " << a.name << endl;
        cout << "Guarantee period: " << a.guarant << endl;
        cout << "Date of buy: ";
        cout.fill('0');
        cout.width(2); cout << a.dateOfBuy.d << ".";
        cout.width(2); cout << a.dateOfBuy.m << ".";
        cout << a.dateOfBuy.y << endl << endl;
    }
    File.close();
    return true;
}

void enterFile(string path) {
    Technic a;
    int n;
    ofstream inFile(path, ios::binary | ios::app);
    cout << "Input number of techniquec: "; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Name of technique: "; cin >> a.name; cin.ignore();
        cout << "Date of buy(d m y; e.g: 4 11 2022): "; cin >> a.dateOfBuy.d; cin >> a.dateOfBuy.m; cin >> a.dateOfBuy.y; cin.ignore();
        cout << "Days Warranty: "; cin >> a.guarant; cin.ignore();
        inFile.write((char*)&a, sizeof(Technic));
        cout << endl;
    }
    inFile.close();
}

void outExpired(string inPath, string outPath) {
    Technic a;
    ifstream inFile(inPath, ios::binary);
    ofstream outFile(outPath, ios::binary | ios::trunc | ios::out);
    while (inFile.read((char*)&a, sizeof(Technic))) {
        if (!guarantee(a.dateOfBuy.y, a.dateOfBuy.m, a.dateOfBuy.d, a.guarant)) {
            outFile.write((char*)&a, sizeof(Technic));
        }
    }
    inFile.close();
    outFile.close();
}

bool guarantee(int year, int month, int day, int guarant) {
    int now_year, now_month, now_day, JDN1, JDN2;
    tm newtime;
    time_t now = time(NULL);
    localtime_s(&newtime, &now);
    now_year = 1900 + newtime.tm_year;
    now_month = 1 + newtime.tm_mon;
    now_day = newtime.tm_mday;
    JDN1 = JDN(now_year, now_month, now_day);
    JDN2 = JDN(year, month, day);
    if (JDN1 - JDN2 > guarant) {
        cout << "фолс";
        return false;
    }
    else {
        return true;
    }
}

int JDN(int year, int month, int day) {
    int a, y, m, JDN;
    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 34025;
    return JDN;
}