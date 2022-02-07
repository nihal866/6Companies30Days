//  https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart

class Solution{
public:
    int height(int n){
        int ans = (-1 + sqrt(1 + (8*n))) / 2;
        return ans;
    }
};