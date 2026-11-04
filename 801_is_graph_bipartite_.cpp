class Solution {
private:
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph){
        color[node] = col;
        for(auto adj : graph[node]){
            if(color[adj]==-1){
                if(dfs(adj,!col,color,graph)==false) return false;
            }else if(col==color[adj]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};