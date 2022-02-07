//  https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        int i,c=1;
        stack<int> s;
        for(i=n-1;i>=0;i--)
        {
            if(!s.empty())
            {
                if(s.top()<=arr[i])
                {
                    while(!s.empty() && s.top()<=arr[i])
                    s.pop();
                    s.push(arr[i]);
                    if(s.size()==3)
                    break;
                }
                else
                {
                    s.push(arr[i]);
                    if(s.size()==3)
                    break;
                }
            }
            else
                s.push(arr[i]);
        }
        vector<int> a;
        if(s.size()==3)
        {
            a.push_back(s.top());
            s.pop();
            a.push_back(s.top());
            s.pop();
            a.push_back(s.top());
            s.pop();
        }
        return a;
    }
};