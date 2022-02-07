//  https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        for(int len = 2; len <= n; len++){ 
            for(int i = 1; i + len - 1 <= n; i++){ 
            dp[i][i+len-1] = INT_MAX;
                for(int j = i ; j <= i + len - 1; j++){ 
                    dp[i][i+len-1] = min(dp[i][i+len-1], j + max(dp[i][j-1], dp[j+1][i+len-1]));
                }
            }
            
        }
        return dp[1][n];
    }
};
