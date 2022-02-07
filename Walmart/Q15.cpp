//  https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int D, int d) 
	{
        long dividend = (long) D;
        long divisor = (long) d;
        
        if (dividend == INT32_MIN && divisor == -1) 
            return INT32_MAX;
            
		bool negative_result = (dividend < 0) ^ (divisor < 0);

		divisor = labs(divisor);
		dividend = labs(dividend);

		if (divisor > dividend)
			return 0;

		long quotient = (long) 1;
		long temp = (long) divisor;
		
		while ((temp << 1) <= dividend) 
		{
			temp <<= 1;
			quotient <<= 1;
		}
		
		quotient += divide((dividend - temp), divisor);

		if (negative_result)
			quotient = -quotient;
		
		return quotient;
	}
};