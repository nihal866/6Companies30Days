//  https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    bool kcan(vector<int>& piles, long mid, int h){
        long count = 0;
        for(auto a : piles){
            count += a/mid;
            count += ((a%mid) ? 1 : 0);
        }
        return (count <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        long low = 1, high = 1e9 + 1;
        while(low < high){
            long mid = (low+high)>>1;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            if(kcan(piles, mid, h)){
                high = mid;
                //high = mid-1;
            }
            else    low = mid+1;
        }
        return low;
    }
};