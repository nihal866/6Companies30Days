// Find max 10 numbers in a list having 10M entries.
/* I cannot find the real question in internet, so
i looked one medium level program from the same company tag(Goldman Sachs) */
// https://practice.geeksforgeeks.org/problems/edit-distance3702/1/
// EDIT DISTANCE


class Solution {
 public:
  int getMinDis(string w1,string w2,int ind1,int ind2,vector<vector<int>> &dp){
    
        if(ind1 == -1) return ind2+1; 
        if(ind2 == -1) return ind1+1; 
    
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2]; 
    
        if(w1[ind1] == w2[ind2]) dp[ind1][ind2] = getMinDis(w1,w2,ind1-1,ind2-1,dp);
        else{
            int insert = getMinDis(w1,w2,ind1 ,ind2-1  ,dp); // insertion
            int remove = getMinDis(w1,w2,ind1-1 ,ind2  ,dp); // deletion
            int replac = getMinDis(w1,w2,ind1-1 ,ind2-1,dp); // replacment
        
            dp[ind1][ind2] = min({insert ,remove , replac}) + 1; 
        }
    
        return dp[ind1][ind2]; 
    }
    int editDistance(string s, string t) {
        vector<vector<int>>dp(s.size(), vector<int>(t.size(), -1));
        return getMinDis(s,t,s.size()-1,t.size()-1,dp);
    }
};