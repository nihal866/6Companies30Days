//  https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/1/

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    vector<int> arr;
    //Function to return a list of integers denoting spiral traversal of matrix.
    
    void store(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int c, char ch, int i, int j){
        if(i<0 || j<0 || i>=r || j>=c || visited[i][j])   return;
        visited[i][j] = true;
        arr.push_back(matrix[i][j]);
        if(ch == 'r'){
            if(j==c-1 || visited[i][j+1])   ch = 'd',   i++;
            else    j++;
        }
        else if(ch == 'l'){
            if(j==0 || visited[i][j-1]) ch = 'u',   i--;
            else    j--;
        }
        else if(ch == 'd'){
            if(i==r-1 || visited[i+1][j])   ch = 'l',   j--;
            else    i++;
        }
        else{
            if(i==0 || visited[i-1][j]) ch = 'r',   j++;
            else    i--;
        }
        store(matrix, visited, r, c, ch, i, j);
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<vector<bool>> visited(r, vector<bool>(c,false));
        store(matrix, visited, r, c, 'r', 0, 0);
        return arr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends