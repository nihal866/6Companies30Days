//  https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int change(vector<int>& v){
        vector<int> res;
        for(auto a : v){
            auto it = lower_bound(res.begin(), res.end(), a);
            if(it != res.end())  *it = a;
            else    res.push_back(a);
        }
        return res.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_map<int, int> mp;
        for(int i = 0; i < M; i++)  mp[B[i]]++;
        vector<int> v;
        for(int i = 0; i < N; i++){
            if(mp.count(A[i]))  v.push_back(A[i]);
        }
        return (N+M - 2*change(v));
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends