// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define fri(i,a,b)  for(int i = a; i < b; i++)
class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        if(n==0 || k==0)  return 0;
        int dp[k+1][n], mx;
        fri(i, 0, n)    dp[0][i] = 0;
        fri(i, 0, k+1)  dp[i][0] = 0;
        fri(i, 1, k+1){
            fri(j, 1, n){
                mx = 0;
                fri(p, 0, j)    mx = max(mx, dp[i-1][p] + A[j] - A[p]);
                mx = max(mx, dp[i][j-1]);
                dp[i][j] = mx;
            }
        }
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends