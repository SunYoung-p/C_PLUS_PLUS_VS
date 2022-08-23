/*
Bank Manager ���α׷�

1. Version : 2.0 (220815)
2. ������
 - ����ü AccountInfo �� Ŭ������ ����
 - AccountInfo �� �� ���� char �迭�� ���� �Ҵ� �ϴ� ������ ����
 - ��ü �迭�� ��ü ������ �迭�� ����
*/

#pragma once

/* Ŭ���� ���� */
class Account
{
private:
	char* myID;
	char* myName;
	int myMoney;

public:
	Account(char *id, char *name, int money);
	~Account();
};

/* �Լ� ���� */
int RunBankManager();
void MakeAccount();
void PrintMenu();

/* enum ��� */
enum KEY
{
	MAKE =1 ,
	DEPOSIT,
	WITHDRAW,
	SHOWINFO,
	EXIT
};
