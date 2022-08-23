#include <iostream>
#include "BOOK_OOP_PRJ_01.h"
using namespace std;

int RunBankManager() { return 0; }

/* 전역 변수 */
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
		<< "Accout 초기화 완료 " << endl;
}

Account::~Account()
{
	delete[] info[0]->myID;
	delete[] info[0]->myName;
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

void MakeAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;

	cout << "\n [계좌 개설] \n";
	cout << "(1) ID 입력 : "; cin >> id;
	cout << "(2) Name 입력 : "; cin >> name;
	cout << "(3) Money 입력 : "; cin >> money;

	info[0] = new Account(id, name, money);
}
