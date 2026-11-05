class Solution {
private:
    bool dfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        visited[node] = 1;
        for(auto adjacent : adj[node]){
            if(!visited[adjacent]){
                if(dfs(adjacent,visited,adj)==true) return true;
            }else if(visited[adjacent]==1) return true;
        }
        visited[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n,0);
        vector<vector<int>> adj(numCourses);

        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,visited,adj)==true) return false;
            }
        }
        return true;
    }
};