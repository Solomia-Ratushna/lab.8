
// Lab_8_1_1.cpp
// < Ратушна Соломія Юріївна >
// Лабораторна робота № 8.1.1
//  Пошук та заміна символів у літерному рядку ітераційнимм способам.
// Варіант 22

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* Change(char* str)
{
    if (strlen(str) < 1)
        return str;
    char* tmp = new char[101];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;

    while (str[i] != 0)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
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
int Count(const char* str, const char* cs)
{
    int k = 0;
    for (int i = 0; cs[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++)
            if (cs[i] == str[j])
                k++;
    return k;
}


int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char cs[] = "+-=";
    cout << "calc " << Count(str, cs) << endl;

    char* dest = new char[75];

    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}