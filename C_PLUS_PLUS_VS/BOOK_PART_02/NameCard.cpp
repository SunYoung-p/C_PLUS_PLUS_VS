#include <iostream>
#include "NameCard.h"

using namespace std;

NameCard::NameCard(char* name_, char* com_, char* phone_, int rank_)
{
	int len = 0;

	len = strlen(name_);
	name = new char[len+1];
	strcpy_s(name, len+1, name_);
	name[len] = '\0';

	len = strlen(com_);
	company = new char[len+1];
	strcpy_s(company, len+1, com_);
	company[len] = '\0';

	len = strlen(phone_);
	phone = new char[len + 1];
	strcpy_s(phone, len+1, phone_);
	phone[len] = '\0';

	if (rank_ < Rank::CLERK || rank_ > Rank::MANAGER)
	{
		cout << "rank 초기화 실패" << endl;
		rank = Rank::CLERK;
		return;
	}

	rank = rank_;
}

NameCard::~NameCard()
{
	delete[] name;
	delete[] company;
	delete[] phone;
}

void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: " << rank << endl << endl;
}