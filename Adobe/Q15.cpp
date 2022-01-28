/*  Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9”
 or “10” and “10.1”. Find out which one is more recent? Strings can be empty also */
 
 #include<bits/stdc++.h>
 using namespace std;

class Solution{
public:
    string olderVersion(string s1, string s2){
        if(s1 == "")    return s2;
        if(s2 == "")    return s1;
        queue<long long> q1, q2;
        bool dot = false;
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == '.'){
                q1.push(count);
                count = 0;
            }
            else    count = count*10 + (s1[i]-'0');
        }
        q1.push(count);
        count = 0;
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == '.'){
                q2.push(count);
                count = 0;
            }
            else    count = count*10 + (s2[i]-'0');
        }
        q2.push(count);
        while(!q1.empty() && !q2.empty() && q1.front()==q2.front()){
            q1.pop();
            q2.pop();
        }
        if(q1.empty() && q2.empty())    return "Versions are Same";
        if(q1.empty())  return s2;
        if(q2.empty())  return s1;
        return ((q1.front() > q2.front())?s1:s2);
    }
};

int main(){
    string s1, s2;
    cin>>s1>>s2;
    Solution obj;
    cout<<obj.olderVersion(s1, s2)<<endl;
    return 0;
}