//  https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool ones = false;
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
                if(grid[i][j] == 1) ones = true;
            }
        }
        if(q.empty()){
            if(ones)    return -1;
            return 0;
        }
        int time = 0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int tt = q.front().second;
            time = tt;
            q.pop();
            if(i-1>=0 && grid[i-1][j]==1){
                q.push({{i-1, j}, tt+1});
                grid[i-1][j] = 2;
            }
            if(j-1>=0 && grid[i][j-1]==1){
                q.push({{i, j-1}, tt+1});
                grid[i][j-1] = 2;
            }
            if(i+1<n && grid[i+1][j]==1){
                q.push({{i+1, j}, tt+1});
                grid[i+1][j] = 2;
            }
            if(j+1<m && grid[i][j+1]==1){
                q.push({{i, j+1}, tt+1});
                grid[i][j+1] = 2;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};