// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, ans = INT_MAX, sum = 0, n = nums.size();
        while(r < n && l<n){
            sum += nums[r++];
            while(sum >= target){
                ans = min(ans, r-l);
                sum -= nums[l++];
            }
        }
        if(ans == INT_MAX)  return 0;
        return ans;
    }
};