//  https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> ans;
    vector<string> arr{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int a[], int n, int i, string st){
        if(i == n){
            ans.push_back(st);
            return;
        }
        int num = a[i]-2;
        for(char c : arr[num])  solve(a, n, i+1, st+c);
    }
    vector<string> possibleWords(int a[], int N)
    {
        solve(a, N, 0, "");
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends