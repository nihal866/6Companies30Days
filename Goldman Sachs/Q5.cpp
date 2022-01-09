// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    long long arr[n];
        arr[0] = 1;
        long long next, twos = 2, threes = 3, fives = 5;
        int i2 =0, i3 = 0, i5 = 0;
        for(int i = 1; i < n; i++){
            next = min(twos, min(threes, fives));
            if(arr[i-1] != next)    arr[i] = next;
            else    i--;
            if(next == twos){
                i2++;
                twos = arr[i2]*2;
            }
            else if(next == threes){
                i3++;
                threes = arr[i3]*3;
            }
            else if(next == fives){
                i5++;
                fives = arr[i5]*5;
            }
        }
        return next;
	}
};