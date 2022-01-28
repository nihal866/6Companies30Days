//  https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        int n = s.size();
        string ans = "";
        if(s[0]>='A' && s[0]<='Z')  s[0] = (s[0]+32);
        ans += s[0];
        for(int i = 0; i < n-1; i++){
            if(s[i+1]>='A' && s[i+1]<='Z'){
                ans += " ";
                s[i+1] = (s[i+1]+32);
            }
            ans += s[i+1];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends