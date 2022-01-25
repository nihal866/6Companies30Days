//  https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        if(D == 1)  return 1;
        int count = 0, i = 1, sum = 0;
        while(1){
            sum += i++;
            count++;
            if(sum == D)   return count;
            if(sum>D && (sum-D)%2==0)   return count;
        }
        return 10;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends