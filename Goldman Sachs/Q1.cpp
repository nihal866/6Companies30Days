// Ques1: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for(auto a : string_list){
            string ns = a;
            sort(ns.begin(), ns.end());
            mp[ns].push_back(a);
        }
        for(auto a : mp)    ans.push_back(a.second);
        return ans;
    }
};