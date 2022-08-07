#include <iostream>
#include "BOOK_PART_02\NameCard.h"
using namespace std;

int main()
{
	NameCard n("Lee", "ABCEng", "010-1111-2222", 1);
	NameCard m("Lee", "ABCEng", "010-1111-2222", 1);
	NameCard o("Lee", "ABCEng", "010-1111-2222", 1);

	n.ShowNameCardInfo();
	m.ShowNameCardInfo();
	o.ShowNameCardInfo();

	getchar();
	getchar();
	return 0;
}