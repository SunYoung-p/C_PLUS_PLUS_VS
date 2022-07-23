#include <iostream>
#include "PRJ_01_BANK_MANAGER.h"

using namespace std;

int main_bank();

int main()
{

	main_bank();
	

	getchar();
	getchar();
	return 0;
}

int main_bank()
{
	int n = 0;

	while (n != 5)
	{
		PrintMenu();
		cin >> n;
		cout << endl;

		switch (n)
		{
		case 1:
			BANK_INFO[BANK_CNT] = MakeAccount();
			BANK_CNT++;
			break;
		case 2:
			if (RunDeposit(GetDepositInfo()) == -1)
				cout << "ID가 잘못되었습니다. " << endl;
			else
				cout << "입금완료" << endl;

			break;
		case 3:
			if (RunWithDraw(GetWithDrawInfo()) == -1)
				cout << "ID가 잘못되었거나, 잔액이 부족합니다. " << endl;
			else
				cout << "출금완료" << endl;
			break;
		case 4:
			PrintAccount();
			break;
		case 5:
			cout << "프로그램을 종료합니다." << endl;
			break;
		default: cout << "입력이 잘못되었습니다" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}
