//  https://leetcode.com/problems/stone-game/

class Solution {
public:
    int dp[501][501]={};
    
    int takeStone(bool alex, int l, int h, vector<int>& piles)
    {
        if(l>h) return 0;
        if(l==h) return piles[l];
        
        
        if(dp[l][h]!=-1) return dp[l][h];
        
        
        if(alex)    
            dp[l][h] = max(piles[l]+takeStone(!alex,l+1,h,piles),piles[h]+takeStone(!alex,l,h-1,piles));
        
        
        else
            dp[l][h] = min(-piles[l]+takeStone(!alex,l+1,h,piles),-piles[h]+takeStone(!alex,l,h-1,piles));

        return dp[l][h];
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        
        
        return takeStone(true,0,n-1,piles) > 0;        
    }
};