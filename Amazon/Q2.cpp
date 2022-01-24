// https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, count, j, n = arr.size(), flag;
        for(int i = 1; i < n; i++){
            count = 1;
            flag = 0;
            j = i;
            while(j<n && arr[j]>arr[j-1]){
                j++;
                count++;
            }
            while(j!=i && j<n && arr[j]<arr[j-1]){
                j++;
                flag++;
                count++;
            }
            if(j!=i && flag && count>2) ans = max(ans, count),    j--;
            i = j;
        }
        return ans;
    }
};