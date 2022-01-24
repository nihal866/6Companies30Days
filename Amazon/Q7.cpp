// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int arr[26] = {0};
		    vector<int> idx(26, -1);
		    int n = A.size();
		    for(int i = 0; i < n; i++){
		        char m = '#';
		        int ind = n;
		        if(!arr[A[i]-'a']){
		            idx[A[i]-'a'] = i;
		            arr[A[i]-'a']++;
		        }
		        else    idx[A[i]-'a'] = -1;
		        for(int i = 0; i < 26; i++){
		            if(idx[i]!=-1 && idx[i]<ind){
		                ind = idx[i];
		                m = 'a'+i;
		            }
		        }
		        A[i] = m;
		    }
		    return A;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends