// https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/
// 0ms, 6.7mb

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 == str2)    return str1;
        int n = str1.size();
        int m = str2.size();
        int g = __gcd(n, m);
        string ans = "";
        for(int i = 0; i < g; i++){
            if(str1[i] != str2[i])  return "";
            ans += str1[i];
        }
        for(int i = 0; i < n/g; i++){
            string ns = str1.substr(i*g, g);
            if(ns != ans)   return "";
        }
        for(int i = 0; i < m/g; i++){
            string ns = str2.substr(i*g, g);
            if(ns != ans)   return "";
        }
        return ans;
    }
};