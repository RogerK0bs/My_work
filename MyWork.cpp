#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
enum Board { Ver_board = 179, Corner_UL = 218, Corner_UR = 191, Corner_DL = 192, Corner_DR = 217, Hor_board = 196 };
enum ConsoleColor {
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, Yellow = 14, White = 15
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int n;// какое то Git для проверки
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите размер поля = ";
	cin >> n;
	setlocale(LC_ALL, "C");
	for (size_t i = 0; i <= n; i++)
	{
		for (size_t j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0)cout << (char)Corner_UL;
			else if (i == 0 && j == n)cout << (char)Corner_UR;
			else if (i == n && j == 0)cout << (char)Corner_DL;
			else if (i == n && j == n)cout << (char)Corner_DR;
			else if (i == 0 || i == n)cout << (char)Hor_board << (char)Hor_board;
			else if (j == 0 || j == n)cout << (char)Ver_board;
			else if ((i + j) % 2 == 0)
			{
				SetColor(Black, White);
				cout << "  ";
				SetColor(White, Black);
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;

		
	}
	_getch();
}
