// Lab_8_1_2.cpp
// < Ратушна Соломія Юріївна >
// Лабораторна робота № 8.1.2
//  Пошук та заміна символів у літерному рядку рекурсивним способам.
// Варіант 22

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
	

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			strcat(t, "**");
			return Change(dest, str, t + 2, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
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
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	
	char cs[] = "+-=";
	cout << "calc " << Count(str, cs) << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}
