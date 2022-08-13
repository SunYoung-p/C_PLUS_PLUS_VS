#include <iostream>
#include <cstring>
using namespace std;

class ObjArr_Person
{
private:
	char * name;
	int age;
public:
	ObjArr_Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1; // \0 앞까지의 문자 개수만 센다
		name = new char[len];
		strcpy_s(name, len, myname); // \0을 포함해서 카피가 된다.
		age = myage;
	}
	ObjArr_Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << endl;
	}
	~ObjArr_Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int ObjArr()
{
	ObjArr_Person parr[3];
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, len, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();

	return 0;
}