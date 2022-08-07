#pragma once
class NameCard
{
	enum Rank
	{
		CLERK=1,
		SENIOR=2,
		ASSIST=3,
		MANAGER=4
	};
private:
	char* name;
	char* company;
	char* phone;
	int rank;

public:
	NameCard(char* name_, char* com_, char* phone_, int rank);
	~NameCard();
	void ShowNameCardInfo();
};