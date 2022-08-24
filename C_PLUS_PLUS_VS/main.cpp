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
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case SHOWINFO:
			PrintAccount();
			break;
		case EXIT:
			ExitBank();
			exit = true;
			break;
		default:
			cout << "�߸��� �� �Է� \n";
			break;
		}


		cout << "\n\n";

	}

	return 0;
}