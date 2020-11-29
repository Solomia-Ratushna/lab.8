// Lab_8_1_3.cpp
// < Ратушна Соломія Юріївна >
// Лабораторна робота № 8.1.3
// Варіант 22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char* Change(char* str)
{
    if (strlen(str) < 3)
        return str;
    char* tmp = new char[strlen(str) * 3 / 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    int i = 0;
    while (str[i] != 0)
    {
        if ((str[i] == '+' )
            ||
            (str[i] == '-' )
            ||
            (str[i] == '='))
        {

            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}



int Count(char* s, const char* cs)
{
    int k = 0,
        pos = 0;
    char* t;
    while (t = strpbrk(s + pos, cs))
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}
int main()
{
    char str[201];

    cout << "Enter string: ";
    cin.getline(str, 200); cout << endl;
    char cs[] = "+-=";
    cout << "calc " << Count(str, cs) << endl;
    cout << "Modified string (param) : " << str << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
