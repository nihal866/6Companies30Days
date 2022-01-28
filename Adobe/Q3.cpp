//  https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    long long mod = 1000000007;
    long long int mul(long long int a, int times){
        long long int ans = 1;
        for(int i = 1; i <= times; i++) ans = (ans*a)%mod;
        return ans;
    }
    int kvowelwords(int N, int K) {
        long long int dp[N+1][K+1] = {0};
        long long int sum = 1;
        for(int i = 1; i <= N; i++){
            sum = (sum*21)%mod;
            dp[i][0] = sum;
            for(int j = 1; j <= K; j++){
                if(j > i)   dp[i][j] = 0;
                else if(j == i)  dp[i][j] = mul(5, i);
                else    dp[i][j] = dp[i-1][j-1] * 5;
                dp[i][j] %= mod;
                sum += dp[i][j];
                sum %= mod;
            }
        }
        return sum;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends