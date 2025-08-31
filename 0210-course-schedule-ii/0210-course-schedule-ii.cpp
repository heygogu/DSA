class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int>ans;
        
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // int courseCount = 0;

        while(!q.empty()){
            int course = q.front(); q.pop();
            // courseCount++;
            ans.push_back(course);
            for(auto neighbor:adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        // return ans.size()==numCourses ? ans : ans.resize(0);

        if(ans.size()==numCourses){
            return ans;
        }
        ans.resize(0);
        return ans;
    }
};