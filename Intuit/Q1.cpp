//  https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    if(n==1)    return arr[0];
	    if(n == 2)  return abs(arr[0]-arr[1]);
	    int sum = 0;
	    for(int i = 0; i < n; i++)  sum += arr[i];
	    int dp[n+1][sum+1];
	    memset(dp, 0, sizeof(dp));
	    for(int i = 0; i <= n; i++) dp[i][0] = 1;
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= sum; j++){
	            if(arr[i-1] <= j)   dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];
	            else    dp[i][j] = dp[i-1][j];
	        }
	    }
	    int ans = 0;
	    for(int i = 0; i <= sum/2; i++){
	        if(dp[n][i])    ans = max(ans, i);
	    }
	    return ((sum-ans)-(ans));
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends