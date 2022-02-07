//  https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i = 0 ; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        vector<int> v, em;
        vector<bool> visited(numCourses, false);
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!indegree[i])    q.push(i),  visited[i] = true;
        }
        int node;
        while(!q.empty()){
            node = q.front();
            v.push_back(node);
            q.pop();
            for(auto a: adj[node]){
                indegree[a]--;
                if(indegree[a] == 0)    q.push(a);
            }
        }
        if(v.size() == numCourses)  return v;
        return em;
    }
};