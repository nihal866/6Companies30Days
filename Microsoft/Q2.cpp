//  https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    vector<int> indegree(N, 0);
	    for(auto a: prerequisites){
	        adj[a.second].push_back(a.first);
	        indegree[a.first]++;
	    }
	    vector<bool> visited(N, false);
	    queue<int> q;
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0)    q.push(i),  visited[i] = true;
	        //cout<<indegree[i]<<" ";
	    }
	    //cout<<endl;
	    int temp, count = 0;
	    while(!q.empty()){
	        temp = q.front();
	        //cout<<temp<<" ";
	        q.pop();
	        count++;
	        for(auto a : adj[temp]){
	            indegree[a]--;
	            if(indegree[a] == 0)    q.push(a),  visited[a] = true;
	        }
	    }
	    if(count == N)  return true;
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends