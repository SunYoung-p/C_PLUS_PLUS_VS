#include <iostream>
#include "BOOK_OOP_PRJ_01.h"
using namespace std;

int RunBankManager() { return 0; }

/* ���� ���� */
Account * info[100];

Account::Account(char *id, char *name, int money)
{
	int len = 0;

	len = strlen(id) + 1;
	myID = new char[len];
	strcpy_s(myID, len, id);

	len = strlen(name) + 1;
	myName = new char[len];
	strcpy_s(myName, len, name);

	myMoney = money;

	cout << myID << endl << myName << endl << myMoney << endl
		<< "Accout �ʱ�ȭ �Ϸ� " << endl;
}

Account::~Account()
{
	delete[] info[0]->myID;
	delete[] info[0]->myName;
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

void MakeAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;

	cout << "\n [���� ����] \n";
	cout << "(1) ID �Է� : "; cin >> id;
	cout << "(2) Name �Է� : "; cin >> name;
	cout << "(3) Money �Է� : "; cin >> money;

	info[0] = new Account(id, name, money);
}
