//  https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

class Solution{
    int sum(Node* root)
    {
        if(root == NULL)return 0;
        return sum(root->left)+sum(root->right)+root->data;
    }
    void toSumTree(Node *root)
    {
        // Your code here
        if(root == NULL)return;
        
        int s = sum(root)-root->data;
        root->data = s;
        
        toSumTree(root->left);
        toSumTree(root->right);
    }
};