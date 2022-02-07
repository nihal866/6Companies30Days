//  https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited, int node){
        visited[node] = true;
        for(auto a: adj[node]){
            if(!visited[a]) dfs(adj, visited, a);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        vector<bool> visited(n+1, false);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};