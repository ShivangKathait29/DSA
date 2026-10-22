class Solution {
public:
    void province(vector<vector<int>>& isConnected,int i,vector<bool>& visited){
        visited[i] = true;
        for(int j=0;j<isConnected[0].size();j++){
            if(!visited[j] && isConnected[i][j]==1){
                province(isConnected,j,visited);
            }
        }        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited (n,false);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]) {
                province(isConnected,i,visited);
                ans++;
            }
        }
        return ans;
    }
};