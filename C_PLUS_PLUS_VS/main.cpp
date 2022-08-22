#include <iostream>
#include "PROJECT\BOOK_OOP_PRJ_01.h"

using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i*j << endl;
		}

		cout << endl;
	}

	return 0;
}