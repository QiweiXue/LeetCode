#include "PalindromeNumber.h"



bool PalindromeNumber::isPalindrome(int x)
{
	if(x < 0)
		return false;
	int x0 = x;
	int bits = 1;
	while ((x0 = x0 / 10) > 0)
		++bits;
	for(int i = 0 ; i < bits/2; i++)
	{
		if (getBits(x, i) != getBits(x, bits - i - 1))
			return false;
	}
	return true;
}

int PalindromeNumber::getBits(int x, int b)
{
	int remain;
	while(b >= 0)
	{
		remain = x % 10;
		x = x / 10; 
		--b;
	}
	return remain;
}

