//  https://practice.geeksforgeeks.org/problems/implement-atoi/1/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        long count = 0;
        bool neg = false;
        if(str[0] == '-'){
            neg = true;
            str = str.substr(1, str.size()-1);
        }
        for(char c : str){
            if(isdigit(c))  count = count*10 + (c-'0');
            else    return -1;
        }
        if(neg) count *= -1;
        return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends