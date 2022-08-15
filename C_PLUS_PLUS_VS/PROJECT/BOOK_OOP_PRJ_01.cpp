#include <iostream>
#include "BOOK_OOP_PRJ_01.h"

using namespace std;

Bank BANK_INFO[10];
int BANK_CNT;


int RunBankManager()
{
	int n = 0;
	Account * Info[ACCOUNT_CNT];

	

	while (n != 5)
	{
		PrintMenu();
		cin >> n;
		cout << endl;

		switch (n)
		{
		case MAKE:
			if(MakeAccount(Info) == false)
				cout << "RunBankManager::계좌 생성 실패" << endl;
			break;
		case DEPOSIT:
			if (RunDeposit(GetDepositInfo()) == -1)
				cout << "ID가 잘못되었습니다. " << endl;
			else
				cout << "입금완료" << endl;

			break;
		case WITHDRAW:
			if (RunWithDraw(GetWithDrawInfo()) == -1)
				cout << "ID가 잘못되었거나, 잔액이 부족합니다. " << endl;
			else
				cout << "출금완료" << endl;
			break;
		case INQUIRE:
			PrintAccount();
			break;
		case EXIT:
			cout << "프로그램을 종료합니다." << endl;
			break;
		default: cout << "입력이 잘못되었습니다" << endl;
			break;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
	}

	
	return 0;
}


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

bool MakeAccount(Account(&info)[])
{
	int id = 0, InfoCnt=0;
	char name[100] = { 0 };
	int money = 0;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i].GetIsMake == false)
		{
			InfoCnt = i - 1;
			break;
		}

		if (info[i].GetID == id)
		{
			cout << "MakeAccount::ID 중복 에러" << endl;
			return false;
		}
	}

	cout << "이 름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> money;

	if (money < 0)
	{
		cout << "MakeAccount::입금액이 0보다 작습니다" << endl;
		return false;
	}

	
	return true;
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


bool Account::Deposit(int money)
{
	if (money < 0)
	{
		cout << "Accout::Deposit : 입금액이 잘못되었습니다" << endl;
		return false;
	}

	this->money += money;
	return true;
}

bool Account::WithDraw(int money)
{
	if (GetMoney() < money)
	{
		cout << "Accout::WithDraw : 계좌 잔액보다 출금 요청 금액이 더 큽니다" << endl;
		return false;
	}

	this->money -= money;
	return true;
}