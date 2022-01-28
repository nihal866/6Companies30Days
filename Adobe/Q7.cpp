//  https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    vector<vector<int>> dp(n, vector<int>(n, 0));
	    for(int i = 0; i < n; i++)  dp[i][i] = A[i];
	    for(int i = 0; i < n-1; i++)    dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
	    for(int g = 2; g < n; g++){
	        for(int i = 0; i < n-g; i++){
	            int j = i+g;
	            int left = A[i] + min(dp[i+2][j], dp[i+1][j-1]);
	            int right = A[j] + min(dp[i][j-2], dp[i+1][j-1]);
	            dp[i][j] = max(left, right);
	        }
	    }
	    return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends