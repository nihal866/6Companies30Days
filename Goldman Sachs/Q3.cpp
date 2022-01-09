// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(k <= 1)   return 0;
        int count = 0;
        long long l = 0, r = 0, prod = 1;
        while(r < a.size()){
            prod *= (1ll*a[r]);
            while(prod >= k)    prod /= a[l++];
            count += (r++ - l + 1);
        }
        return count;
    }
};