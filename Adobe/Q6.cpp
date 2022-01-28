//  https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    bool balance(string s){
        int o = 0, cl = 0;
        for(auto c : s){
            if(c == '(')    o++;
            else    cl++;
        }
        return (cl == o);
    }
    void gen(string s, int n){
        if(n==0 && balance(s)){
            ans.push_back(s);
            return;
        }
        if(n)   gen(s+"(", n-1);
        if(!balance(s)) gen(s+")", n);
    }
    vector<string> AllParenthesis(int n) 
    {
        gen("", n);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends