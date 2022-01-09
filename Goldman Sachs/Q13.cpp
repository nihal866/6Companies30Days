// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution {
public:
    string solve(string& s, int& i){
        string res = "";
        while(i < s.size() && s[i]!=']'){
            if(isdigit(s[i])){
                int k = 0;
                while(isdigit(s[i]))    k = (k*10) + (s[i++] - '0');
                i++;
                string ns = solve(s, i);
                while(k--)  res += ns;
                i++;
            }
            else    res += s[i++];
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};