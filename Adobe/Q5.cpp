//  https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#

// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        int limit = (x>1) ? (pow(n, (double)1/x)+1) : n;
        long long mod = 1000000007;
        vector<long long> arr(limit);
        for(int i = 1; i <= limit; i++) arr[i-1] = 1ll*pow(i, x);
        long long dp[limit+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= limit; i++) dp[i][0] = 1;
        for(int i = 1; i <= limit; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i-1] <= j)   dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%mod;
                else    dp[i][j] = dp[i-1][j];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[limit][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends