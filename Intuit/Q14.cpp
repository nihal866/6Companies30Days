//  https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
    int n=a.size();
        if(n==0)
            return 0;
        int m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX-1000));
        int ans=INT_MIN;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                { dp[i][j]=0;
                 flag=1;
                }
                else
                {
                    if(i>0)
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                         //ans=max(ans,dp[i][j]);
                    } 
                    if(j>0)
                    {
                     dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                        // ans=max(ans,dp[i][j]);
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i<n-1)
                {
                    dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                    //ans=max(ans,dp[i][j]);
                }
                if(j<m-1)
                {
                    dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                    //ans=max(ans,dp[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
               ans=max(ans,dp[i][j]);
        }
        if(ans==0 || flag==0)
            return -1;
        return ans;
    }
};