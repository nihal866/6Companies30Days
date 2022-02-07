//  https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& M) {
        vector<vector<int>> ans;
        if (M.empty()) return ans;
        int y = M.size(), x = M[0].size();
        vector<char> dp(y * x);
        for (int i = 0; i < y; i++) {
            dfs(M, dp, i, 0, 1, 0);
            dfs(M, dp, i, x - 1, 2, 0);
        }
        for (int i = 0; i < x; i++) {
            dfs(M, dp, 0, i, 1, 0);
            dfs(M, dp, y - 1, i, 2, 0);
        }
        for (int i = 0; i < y; i++) 
            for (int j = 0; j < x; j++) 
                if (dp[i * x + j] == 3) 
                    ans.push_back({i, j});
        return ans;
    }
private:
    void dfs(const vector<vector<int>>& M, vector<char>& dp, int i, int j, int w, int h) {
        int y = M.size(), x = M[0].size(), ij = i * x + j, newh = M[i][j];;
        if ((dp[ij] & w) || M[i][j] < h) return;
        dp[ij] += w;
        if (i + 1 < y) dfs(M, dp, i + 1, j, w, newh);
        if (i > 0) dfs(M, dp, i - 1, j, w, newh);
        if (j + 1 < x) dfs(M, dp, i, j + 1, w, newh);
        if (j > 0) dfs(M, dp, i, j - 1, w, newh);
    }
};