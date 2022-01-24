//  https://practice.geeksforgeeks.org/problems/burning-tree/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, vector<Node*>> mp;
        unordered_map<Node*, bool> visited;
        Node* temp;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            visited[curr] = false;
            if(curr->data == target)    temp = curr;
            if(curr->left){
                mp[curr].push_back(curr->left);
                mp[curr->left].push_back(curr);
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr].push_back(curr->right);
                mp[curr->right].push_back(curr);
                q.push(curr->right);
            }
        }
        int ans = 0;
        queue<pair<Node*,int>> qq;
        qq.push({temp, 0});
        visited[temp] = true;
        while(!qq.empty()){
            Node* curr = qq.front().first;
            int count = qq.front().second;
            ans = max(ans, count);
            qq.pop();
            for(Node* a : mp[curr]){
                if(!visited[a]){
                    visited[a] = true;
                    qq.push({a, count+1});
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends