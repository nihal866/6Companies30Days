// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        int a[n+1] = {0};
        vector<int> ans(2, 0);
        for(int i = 0; i < n; i++){
            a[arr[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) ans[1] = i;
            if(a[i] == 2) ans[0] = i;
        }
        return ans;
    }
};