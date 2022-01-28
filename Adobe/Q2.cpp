//  https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        int mx = 1;
        vector<unordered_map<int,int>> v(n);
        unordered_map<int, int> mp;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = arr[i]-arr[j];
                int add = v[j].count(diff) ? v[j][diff] : 1;
                v[i][diff] += add + 1;
                mx = max(mx, v[i][diff]);
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends