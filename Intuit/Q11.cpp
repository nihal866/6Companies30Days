//  https://leetcode.com/problems/construct-quad-tree/

class Solution {
public:
    Node* helper(vector<vector<int>>&grid,int up,int down,int left,int right){
        bool allsame=true;
        for(int i=up;i<down;i++)
            for(int j=left;j<right;j++)
                if(grid[i][j]!=grid[up][left]){allsame=false;break;}
        Node*result;
        if(allsame){
            result = new Node(grid[up][left],1);
        }
        else{
            result = new Node();
            int midrightleft=(left+right)/2;
            int midupdown=(up+down)/2;
            result->topLeft = helper(grid,up,midupdown,left,midrightleft);
            result->topRight = helper(grid,up,midupdown,midrightleft,right);
            result->bottomLeft = helper(grid,midupdown,down,left,midrightleft);
            result->bottomRight = helper(grid,midupdown,down,midrightleft,right);
        }
        return result;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,grid.size(),0,grid.size());
    }
};