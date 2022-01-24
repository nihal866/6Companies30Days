// https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<string> words;
        for(int i = 0; i < n; i++)  words.push_back(contact[i]);
        //sort(words.begin(), words.end());
        vector<vector<string>> ans;
        vector<string> v;
        set<string> st;
        string str = "";
        for(char c : s){
            str += c;
            v.clear();
            st.clear();
            auto pos = lower_bound(words.begin(), words.end(), str);
            for(auto itr = pos; itr != words.end(); itr++){
                string ns = *itr;
                if(ns.find(str))    break;
                st.insert(ns);
            }
            if(st.size() == 0)   v.push_back("0");
            else{
                for(string a : st)  v.push_back(a);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends