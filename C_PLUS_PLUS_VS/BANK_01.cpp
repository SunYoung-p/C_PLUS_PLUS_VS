#include <iostream>
#include "PRJ_01_BANK_MANAGER.h"

using namespace std;

Bank BANK_INFO[10];
int BANK_CNT;

void PrintMenu()
{
	cout << "-----Menu-----" << endl
		<< "1. 계좌개설" << endl
		<< "2. 입 금" << endl
		<< "3. 출 금" << endl
		<< "4. 계좌정보 전체 출력" << endl
		<< "5. 프로그램 종료" << endl
		<< "선택: ";
}

void PrintAccount()
{
	for (int i = 0; i < BANK_CNT; i++)
	{
		cout << endl;
		cout << "계좌ID: " << BANK_INFO[i].id << endl
			<< "이 름: " << BANK_INFO[i].name << endl
			<< "잔 액: " << BANK_INFO[i].money << endl;
		cout << endl;
	}
}

Bank MakeAccount()
{
	Bank n;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> n.id;

	cout << "이 름: ";
	cin >> n.name;

	cout << "입금액: ";
	cin >> n.money;

	return n;
}


Bank GetDepositInfo()
{
	Bank n;

	cout << "[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> n.id;

	cout << "입금액: ";
	cin >> n.money;

	return n;
}


int RunDeposit(Bank n)
{
	for (int i = 0; i < BANK_CNT; i++)
	{
		if (BANK_INFO[i].id == n.id)
		{
			BANK_INFO[i].money += n.money;

			return 1;
		}
	}

	return -1;
}


Bank GetWithDrawInfo()
{
	Bank n;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> n.id;

	cout << "출금액: ";
	cin >> n.money;

	return n;
}


int RunWithDraw(Bank n)
{
	for (int i = 0; i < BANK_CNT; i++)
	{
		if (BANK_INFO[i].id == n.id && BANK_INFO[i].money >= n.money)
		{
			BANK_INFO[i].money -= n.money;

			return 1;
		}
	}

	return -1;
}