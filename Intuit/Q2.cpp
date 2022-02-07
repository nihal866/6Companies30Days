//  https://practice.geeksforgeeks.org/problems/word-search/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, vector<int>&row, vector<int>& col, int i, int j, int k){
        if(k == word.size())    return true;
        visited[i][j] = true;
        for(int p = 0; p < 4; p++){
            int nr = i + row[p];
            int nc = j + col[p];
            if(nr<0 || nr==board.size() || nc<0 || nc==board[0].size() || visited[nr][nc] || board[nr][nc]!=word[k])    continue;
            if(dfs(board, word, visited, row, col, nr, nc, k+1))    return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> row{0, 0, -1, 1};
        vector<int> col{-1, 1, 0, 0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, visited, row, col, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends