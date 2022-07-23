
#ifndef BACN_HEADER
#define BACN_HEADER
typedef struct AccountInfo
{
	int id = 0;
	char name[100] = { 0 };
	int money = 0;
}Bank;

extern Bank BANK_INFO[10];
extern int BANK_CNT;

void PrintMenu();
void PrintAccount();
Bank MakeAccount();
Bank GetDepositInfo();
int RunDeposit(Bank);

#endif // !BACN_HEADER




