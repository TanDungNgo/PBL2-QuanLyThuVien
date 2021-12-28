#ifndef DOHOA_H
#define DOHOA_H
#include <iostream>
#include <Windows.h>
using namespace std;
class Dohoa
{
public:
    void textcolor(int x)
    {
        HANDLE mau;
        mau = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(mau, x);
    }

    void printline(int n, char c)
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << c;
        }
        cout << endl;
    }
};
#endif