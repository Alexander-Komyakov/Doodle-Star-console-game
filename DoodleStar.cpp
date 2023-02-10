// DoodleStar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include "Music.h"
#include "Game.h"
#include "Menu.h"
#include "Records.h"

#include <iostream>
#include <string>
#include <thread>

using namespace std;

//
void PreviewDisplay(const int a, std::string m[][100])
{
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			coutColor(0, 6, m[i][j]);
			if (j == (a - 1))
			{
				cout << "\n";
			}
		}
	}
	cout << endl;
}
void Preview()
{
	const int k = 100;
	string PrevievText = "\n\
		_$$$$___$$$$$$___$$$$___$$$$$\n\
		$$________$$____$$__$$__$$__$$\n\
		_$$$$_____$$____$$$$$$__$$$$$\n\
		____$$____$$____$$__$$__$$__$$\n\
		_$$$$_____$$____$$__$$__$$__$$\n\
\n\
		$$$$$$__$$__$$__$$___$$_$$$$$\n\
		____$$__$$__$$__$$$_$$$_$$__$$\n\
		____$$__$$__$$__$$_$_$$_$$$$$\n\
		$$__$$__$$__$$__$$___$$_$$\n\
		_$$$$____$$$$___$$___$$_$$\n";
	string m[k][k];
	for (int i = 0; i < k; ++i)
	{
		int random = (rand() % (k - 1));
		for (int j = 0; j < k; ++j)
		{
			if (j == random)
			{
				m[i][j] = "|";
			}
			else
			{
				m[i][j] = " ";
			}
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		PreviewDisplay(k, m);
	}
	coutColor(0, 6, PrevievText);
	Sleep(3000);
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	srand(static_cast<unsigned int>(time(0))); //посев для случайных чисел
	//Fullscreen
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	Record recordGames("Record");
	Record recordGamesNight("RecordNight");
	Preview();
	while (true)
	{
		switch (Menu(0, 4))
		{
		case 0:
			system("cls");
			if (recordGames.Get_Record(0) < 100000)
			{
				recordGames.Set_Record(Game(recordGames.Get_Record(0), 32, 20)); //Старт игры
			}
			else if (recordGames.Get_Record(0) >= 100000)
			{
				switch (Menu(1, 2))
				{
				case 0:
					system("cls");
					recordGames.Set_Record(Game(recordGames.Get_Record(0), 32, 20)); //Старт игры
					break;
				case 1:
					system("cls");
					recordGamesNight.Set_Record(Game(recordGamesNight.Get_Record(0), 5, 3)); //Старт игры
					break;
				default:
					cout << "Unknown"; //В ином случае вывести Unknown(Неизвестно)
					break;
				}
			}
			break;
		case 1:
			Info(); //Вывод информации о игре
			break;
		case 2:
			system("cls");
			GoToXY(0, 2);
			//Отображение рекордов
			coutColor(0, 4, "Обычный режим\n");
			recordGames.DrawRecord();
			if (recordGames.Get_Record(0) >= 100000)
			{
				coutColor(0, 4, "Ночной режим\n");
				recordGamesNight.DrawRecord();
			}
			while (!GetAsyncKeyState(27)) {}
			break;
		case 3:
			exit(0); //Выход
			break;
		default:
			cout << "Unknown"; //В ином случае вывести Unknown(Неизвестно)
			break;
		}
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
