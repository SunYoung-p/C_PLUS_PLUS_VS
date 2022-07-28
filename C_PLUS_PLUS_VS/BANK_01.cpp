#include <iostream>
#include "PRJ_01_BANK_MANAGER.h"

using namespace std;

Bank BANK_INFO[10];
int BANK_CNT;


int RunBankManager()
{
	int n = 0;

	while (n != 5)
	{
		PrintMenu();
		cin >> n;
		cout << endl;

		switch (n)
		{
		case MAKE:
			BANK_INFO[BANK_CNT] = MakeAccount();
			BANK_CNT++;
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

Bank MakeAccount()
{
	Bank n;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> n.id;

	cout << "�� ��: ";
	cin >> n.name;

	cout << "�Աݾ�: ";
	cin >> n.money;

	return n;
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