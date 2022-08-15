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
				cout << "RunBankManager::���� ���� ����" << endl;
			break;
		case DEPOSIT:
			if (RunDeposit(GetDepositInfo()) == -1)
				cout << "ID�� �߸��Ǿ����ϴ�. " << endl;
			else
				cout << "�ԱݿϷ�" << endl;

			break;
		case WITHDRAW:
			if (RunWithDraw(GetWithDrawInfo()) == -1)
				cout << "ID�� �߸��Ǿ��ų�, �ܾ��� �����մϴ�. " << endl;
			else
				cout << "��ݿϷ�" << endl;
			break;
		case INQUIRE:
			PrintAccount();
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default: cout << "�Է��� �߸��Ǿ����ϴ�" << endl;
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
		<< "1. ���°���" << endl
		<< "2. �� ��" << endl
		<< "3. �� ��" << endl
		<< "4. �������� ��ü ���" << endl
		<< "5. ���α׷� ����" << endl
		<< "����: ";
}

void PrintAccount()
{
	for (int i = 0; i < BANK_CNT; i++)
	{
		cout << endl;
		cout << "����ID: " << BANK_INFO[i].id << endl
			<< "�� ��: " << BANK_INFO[i].name << endl
			<< "�� ��: " << BANK_INFO[i].money << endl;
		cout << endl;
	}
}

bool MakeAccount(Account(&info)[])
{
	int id = 0, InfoCnt=0;
	char name[100] = { 0 };
	int money = 0;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
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
			cout << "MakeAccount::ID �ߺ� ����" << endl;
			return false;
		}
	}

	cout << "�� ��: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> money;

	if (money < 0)
	{
		cout << "MakeAccount::�Աݾ��� 0���� �۽��ϴ�" << endl;
		return false;
	}

	
	return true;
}


Bank GetDepositInfo()
{
	Bank n;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> n.id;

	cout << "�Աݾ�: ";
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

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> n.id;

	cout << "��ݾ�: ";
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
		cout << "Accout::Deposit : �Աݾ��� �߸��Ǿ����ϴ�" << endl;
		return false;
	}

	this->money += money;
	return true;
}

bool Account::WithDraw(int money)
{
	if (GetMoney() < money)
	{
		cout << "Accout::WithDraw : ���� �ܾ׺��� ��� ��û �ݾ��� �� Ů�ϴ�" << endl;
		return false;
	}

	this->money -= money;
	return true;
}