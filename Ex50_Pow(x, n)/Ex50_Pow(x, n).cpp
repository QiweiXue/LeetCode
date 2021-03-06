#include <cstdint>

class Solution
{
public:
	double myPow(double x, int n)
	{
		if (n == 0)
			return 1;
		else if(n > 0)
		{
			double temp = myPow(x, n / 2);
			if (n % 2 == 0)
			{
				return temp * temp;
			}
			else
			{
				return temp * temp * x;
			}
		}
		else
		{
			if (n == INT32_MIN)
			{
				double temp = myPow(x, n / 2);
				if (temp != 0)
					return 1.0 / (temp*temp);
				else
					return 0;
			}
			double temp = myPow(x, -n);
			if (temp != 0)
				return 1 / temp;
			else
				return 0;
		}
	}
};

int main()
{
	double res = Solution().myPow(2, -2147483647);
    return 0;
}

