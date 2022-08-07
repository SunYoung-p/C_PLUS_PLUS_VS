#include <iostream>
#include "NameCard.h"

using namespace std;

NameCard::NameCard(char* name_, char* com_, char* phone_, int rank)
{
	int len = 0;

	len = strlen(name_);
	name = new char[len+1];
	strcpy_s(name, len, name_);

	len = strlen(com_);
	company = new char[len+1];
	strcpy_s(company, len, com_);

	len = strlen(phone_);
	phone = new char[len + 1];
	strcpy_s(phone, len, phone_);

	if (rank < Rank::CLERK || rank > Rank::MANAGER)
	{
		cout << "rank �ʱ�ȭ ����" << endl;
		rank = Rank::CLERK;
		return;
	}

	rank = Rank(rank);
}

NameCard::~NameCard()
{
	delete[] name;
	delete[] company;
	delete[] phone;
}

void NameCard::ShowNameCardInfo()
{
	cout << "�̸�: " << name << endl;
	cout << "ȸ��: " << company << endl;
	cout << "��ȭ��ȣ: " << phone << endl;
	cout << "����: " << rank << endl << endl;
}