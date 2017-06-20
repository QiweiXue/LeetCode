#include "ZigZagConversion.h"
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	string s = "PAYPALISHIRING";
	int r = 3;
	cout << s << " : " << ZigZagConversion::convert(s, 3) << endl;
	system("pause");
	return 0;
}