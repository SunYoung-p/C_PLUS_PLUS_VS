#include <iostream>

using namespace std;

typedef struct PhoneBook
{
	char name[20];
	char number[20];
	int IsDeleted = 0;
}PB;

void Menu();
PB GetPBData();
int InserPBData(PB**, PB, int);
void Print_All(PB**, int);
int DeletePBData(PB**, int);

int main()
{
	int n = 0, cnt=0;
	PB m;
	PB* data;

	while (n != 5)
	{
		Menu();
		cin >> n;

		switch (n)
		{
			case 1:
				cout << "[ INSERT ]" << endl;
				m = GetPBData();
				if (InserPBData(&data, m, cnt) == -1)
				{
					cout << "�̹� �����ϴ� �̸��̰ų�, �Է��� �߸�����ϴ�" << endl;
				}
				else
				{
					cout << "�Է� �Ϸ�" << endl;
					cnt++;
				}
				break;
			case 2:
				cout << "[ DELETE ]" << endl;
				if (DeletePBData(&data, cnt) == -1)
				{
					cout << "�������� �ʴ� �̸��̰ų�, �Է��� �߸�����ϴ�" << endl;
				}
				else
				{
					cout << "���� �Ϸ�" << endl;
				}
				break;
			case 3:
				break;
			case 4:
				cout << "[ Print All Data ]" << endl;
				Print_All(&data, cnt);
				break;
			case 5:
				cout << "���α׷� ����" << endl;
				break;
			default:
				cout << "�Է��� �߸��Ǿ����ϴ�" << endl << endl;
				break;
		}

		cout << endl;
	}

	getchar();
	getchar();
	return 0;
}

void Menu()
{
	cout << "***** MENU *****" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Search" << endl;
	cout << "4. Print All" << endl;
	cout << "5. Exit" << endl;
	cout << "Choose the item: ";
}

PB GetPBData()
{
	PB n;

	cout << "Input Name: ";
	cin >> n.name;

	cout << "Input Tel Number: ";
	cin >> n.number;

	return n;
}

int InserPBData(PB** data, PB n, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if ((*data)[i].name == n.name && (*data)[i].IsDeleted != 1)
			return -1;
	}

	if(cnt < 1)
		*data = (PB*)calloc(cnt + 1, sizeof(PB));
	else
		*data = (PB*)realloc(*data, sizeof(PB) * (cnt + 1));

	strcpy_s((*data)[cnt].name, n.name);
	strcpy_s((*data)[cnt].number, n.number);

	return 1;
}

void Print_All(PB** data, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if ((*data)[i].IsDeleted)
		{
			continue;
		}

		cout << "Name: " << (*data)[i].name
			<< "\tTel: " << (*data)[i].number << endl;
	}
}


int DeletePBData(PB** data, int cnt)
{
	char str[20] = { 0 };
	
	cout << "������ �̸� �Է�: ";
	cin >> str;

	for (int i = 0; i < cnt; i++)
	{
		if (strcmp((*data)[i].name, str) == 0)
		{
			(*data)[i].IsDeleted = 1;

			return 1;
		}
	}

	return -1;
}