/*
Bank Manager 프로그램

1. Version : 2.0 (220815)
2. 변경점
 - 구조체 AccountInfo 를 클래스로 변경
 - AccountInfo 에 고객 정보 char 배열은 동적 할당 하는 것으로 변경
 - 객체 배열은 객체 포인터 배열로 변경
*/

#ifndef BACN_HEADER
#define BACN_HEADER


class Account
{
private:
	int id;
	char* name;
	int money;
	bool IsMake;
public:
	Account()
	{
		id = 0;
		money = 0;
		name = NULL;
		IsMake = false;
	}
	Account(int id, char* n, int money, bool IsMake)
		: id(id), money(money), IsMake(IsMake)
	{
		int len = strlen(n) + 1;
		name = new char[len];
		strcpy_s(name, len, n);
	}
	~Account()
	{
		delete[] name;
	}
	int GetID() { return id;	}
	char GetName(){	return id;}
	int GetMoney() { return money; }
	bool GetIsMake() { return IsMake; }
	bool Deposit(int money);
	bool WithDraw(int money);
};

const int ACCOUNT_CNT = 10;

typedef struct AccountInfo
{
	int id = 0;
	char name[100] = { 0 };
	int money = 0;
}Bank;

extern Bank BANK_INFO[10];
extern int BANK_CNT;

int RunBankManager();

void PrintMenu();
void PrintAccount();
bool MakeAccount(Account (&info)[]);
Bank GetDepositInfo();
int RunDeposit(Bank);
int RunWithDraw(Bank);
Bank GetWithDrawInfo();

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
#endif // !BACN_HEADER




