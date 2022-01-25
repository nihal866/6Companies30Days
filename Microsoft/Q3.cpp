//  https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends