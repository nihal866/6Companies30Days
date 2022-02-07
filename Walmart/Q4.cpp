//  https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/

class Solution
{
    public:
    int solve(int a, int b, int i, int j){
        if(i==a && j==b)    return 1;
        if(i>a || j>b)  return 0;
        return (solve(a, b, i+1, j) + solve(a, b, i, j+1));
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        return solve(a, b, 1, 1);
    }
};