#include <iostream>
#include "PROJECT\BOOK_OOP_PRJ_01.h"

using namespace std;

int main()
{
	bool exit = false;
	int sel = 0;

	while (exit == false)
	{
		PrintMenu();
		cin >> sel;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		switch (sel)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			break;
		case WITHDRAW:
			break;
		case SHOWINFO:
			break;
		case EXIT:
			exit = true;
			break;
		default:
			cout << "잘못된 값 입력 \n";
			break;
		}


		cout << "\n\n";

	}

	return 0;
}