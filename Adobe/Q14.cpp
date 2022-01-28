//  https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int right = 1e5, left = 0, mx = -1;
        for(int i = 0; i < k; i++)  pq.push({arr[i][0], {i, 0}}),   mx = max(mx, arr[i][0]),    mx = max(mx, arr[i][0]);
        while(1){
            int mn = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(mx-mn < right-left){
                right = mx;
                left = mn;
            }
            col++;
            if(col == n)    break;
            pq.push({arr[row][col], {row, col}});
            mx = max(mx, arr[row][col]);
        }
        return {left, right};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends