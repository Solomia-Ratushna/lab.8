// Lab_8_1_4.cpp
// < Ратушна Соломія Юріївна >
// Лабораторна робота № 8.1.4
// Варіант 22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int Count(const string s, const string cs)
{
    size_t pos = 0;
    int k = 0;
    while ((pos = s.find_first_of(cs, pos)) != -1)
    {
        k++;
        pos++;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((s.find("+") != -1 || s.find("-") != -1 || s.find("=") != -1))
    {
        if (s.find("+") != -1)
        {
            s = s.replace(s.find("+"), 1, "**");
        }
        if (s.find("-") != -1)
        {
            s = s.replace(s.find("-"), 1, "**");
        }
        if (s.find("=") != -1)
        {
            s = s.replace(s.find("="), 1, "**");
        }
    }

    return s;
}

int main()
{

    string str;
    cout << "Enter string: ";
    getline(cin, str);; cout << endl;
    char cs[] = "+-=";
    cout << "calc " << Count(str, cs) << endl;
    string dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
