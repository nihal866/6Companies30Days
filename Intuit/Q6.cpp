//  https://leetcode.com/problems/find-in-mountain-array/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int max_idx = 0;
        int lo=0, hi = n-1;
        while(lo<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                lo = mid+1;
            else
                hi = mid;
        }
        max_idx = lo;
        lo =0, hi = max_idx;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<target)
                lo = mid+1;
            else if(mountainArr.get(mid)==target)
                return mid;
            else
                hi = mid-1;
        }
        lo =max_idx+1, hi = n-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)>target)
                lo = mid+1;
            else if(mountainArr.get(mid)==target)
                return mid;
            else
                hi = mid-1;
        }
        return -1;
    }
};