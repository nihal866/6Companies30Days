//  https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[], vector<bool>& visited, int node){
        visited[node] = true;
        for(auto a : adj[node]){
            if(!visited[a]) dfs(adj, visited, a);
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> viisited(V, false);
        int count1 = 0;
        for(int i = 0; i < V; i++){
            if(!viisited[i]){
                count1++;
                dfs(adj, viisited, i);
            }
        }
        vector<int> v;
        for(auto a : adj[c]){
            if(a == d)  continue;
            v.push_back(a);
        }
        adj[c] = v;
        v.clear();
        for(auto a : adj[d]){
            if(a == c)  continue;
            v.push_back(a);
        }
        adj[d] = v;
        vector<bool> visited(V, false);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }
        return (count > count1);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends