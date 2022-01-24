// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int l = 0, r = 0;
        vector<int> ans;
        deque<int> dp;
        while(r < n){
            while(!dp.empty() && arr[r]>arr[dp.back()])    dp.pop_back();
            dp.push_back(r);
            if(r-l+1 < k)   r++;
            else{
                ans.push_back(arr[dp.front()]);
                if(dp.front() == l) dp.pop_front();
                l++,r++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends