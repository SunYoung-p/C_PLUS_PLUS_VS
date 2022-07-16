#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int n = 0;

	cout << "숫자를 입력하세요 : ";
	cin >> n;

	for (int i = n; i <= n+9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i*j << std::endl;
		}

		cout << std::endl;
	}

	return 0;
}