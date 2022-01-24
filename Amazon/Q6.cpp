// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends