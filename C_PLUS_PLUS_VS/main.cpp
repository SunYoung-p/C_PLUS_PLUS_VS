#include <iostream>
#include "PRJ_01_BANK_MANAGER.h"

using namespace std;

int main_bank();

int main()
{

	main_bank();
	

	getchar();
	getchar();
	return 0;
}

int main_bank()
{
	int n = 0;

	while (n != 5)
	{
		PrintMenu();
		cin >> n;
		cout << endl;

		switch (n)
		{
		case 1:
			BANK_INFO[BANK_CNT] = MakeAccount();
			BANK_CNT++;
			break;
		case 2:
			if (RunDeposit(GetDepositInfo()) == -1)
				cout << "ID�� �߸��Ǿ����ϴ�. " << endl;
			else
				cout << "�ԱݿϷ�" << endl;

			break;
		case 3:
			if (RunWithDraw(GetWithDrawInfo()) == -1)
				cout << "ID�� �߸��Ǿ��ų�, �ܾ��� �����մϴ�. " << endl;
			else
				cout << "��ݿϷ�" << endl;
			break;
		case 4:
			PrintAccount();
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default: cout << "�Է��� �߸��Ǿ����ϴ�" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}
