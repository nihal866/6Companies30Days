//  https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int count;
    int pos[3] = {-1, 0, +1};
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int row, int col){
        visited[i][j] = true;
        count++;
        for(int k = 0; k < 3; k++){
            for(int p = 0; p < 3; p++){
                int nr = i + pos[k];
                int nc = j + pos[p];
                if(nc<0 || nr<0 || nr==row || nc==col || grid[nr][nc]==0 || visited[nr][nc])   continue;
                dfs(grid, visited, nr, nc, row, col);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !visited[i][j]){
                    count = 0;
                    dfs(grid, visited, i, j, n, m);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends