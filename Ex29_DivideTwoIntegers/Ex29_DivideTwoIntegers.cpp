#include <algorithm>

class Solution 
{
public:
	int divide(int dividend, int divisor) 
	{
		if (dividend == 0)
			return 0;

		long lldividend =  dividend, lldivisor = divisor;
		bool dividendSymbol = dividend < 0 ? 0 : 1;
		bool divisorSymbol = divisor < 0 ? 0 : 1;
		long ldividend = lldividend = std::abs(lldividend);
		long ldivisor = lldivisor = std::abs(lldivisor);

		if (lldividend < lldivisor)
			return 0;

		int divisorBits = 0;
		while (lldivisor != 0)
		{
			lldivisor >>= 1;
			divisorBits++;
		}

		int dividendBits = 0;
		while (lldividend != 0)
		{
			lldividend >>= 1;
			dividendBits++;
		}

		ldivisor <<= dividendBits - divisorBits;
		long res = 0;
		for (int i = 0; i < dividendBits - divisorBits + 1; i++)
		{
			res <<= 1;
			if (ldividend >= ldivisor)
			{
				res |= 1;
				ldividend -= ldivisor;
			}
			ldivisor >>= 1;
		}
		res = (dividendSymbol ^ divisorSymbol) ? (-res) : res;
		if (res > INT32_MAX || res < INT32_MIN)
			return INT32_MAX;
		return res;
	}
};

int main()
{
	int res = Solution().divide(12, 3);
    return 0;
}

