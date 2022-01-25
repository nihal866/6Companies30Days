//  https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

string solve(int n){
    string st = "", mn;
    while(n){
        if(n&1) mn = "1";
        else    mn = "0";
        n >>= 1;
        st = mn + st;
    }
    return st;
}

vector<string> generate(int N)
{
	vector<string> ans;
	for(int i = 1; i <= N; i++){
	    ans.push_back(solve(i));
	}
	return ans;
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
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends