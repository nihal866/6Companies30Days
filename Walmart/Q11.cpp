//  https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
 
    const int mod = 1e9+7;
    
    int maxPerformance(int n, vector<int>& s, vector<int>& eff, int k) {
        vector<pair<int, int>> ord;
        for (int i = 0; i < n; i++)
            ord.push_back({eff[i], s[i]});
        sort(ord.rbegin(), ord.rend()); 
        
        long totspeed = 0, ans = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++){
            int curr_spd = ord[i].second;
            totspeed += curr_spd;
            pq.push(curr_spd);
            
            if(pq.size()>k){          
                totspeed -= pq.top();
                pq.pop();
            }
            
            ans = max(ans,totspeed * ord[i].first); 
        }
        
        return ans % mod;
    }
};