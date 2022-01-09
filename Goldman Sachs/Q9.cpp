// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        vector<int> v(s.size()+1);
        int g = 0, i = 0, k = 1;
        while(i < s.size()){
            if(s[i] == 'I'){
                int j = i;
                while(j >= g){
                    v[j--] = k++;
                }
                g = i+1;
            }
            i++;
        }
        while(i >= g){
            v[i--] = k++;
        }
        string str = "";
        for(auto a : v) str += to_string(a);
        return str;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends