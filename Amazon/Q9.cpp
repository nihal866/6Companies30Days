//  https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(vector<vector<int>>& mat, set<int>& st,int row, int col){
        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                if(mat[i][j] > 0){
                    if(st.find(mat[i][j]) != st.end())    return false;
                    else    st.insert(mat[i][j]);
                }
            }
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        set<int> st;
        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                if(mat[i][j]>0){
                    if(st.find(mat[i][j]) != st.end())  return 0;
                    else    st.insert(mat[i][j]);
                }
            }
        }
        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                if(mat[j][i]>0){
                    if(st.find(mat[j][i]) != st.end()){    
                        //cout<<"**"<<endl;
                        return 0;}
                    else    st.insert(mat[j][i]);
                }
            }
        }
        int arr[3] = {0, 3, 6};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                st.clear();
                if(check(mat, st, arr[i], arr[j]))    continue;
                //cout<<"++"<<endl;
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends