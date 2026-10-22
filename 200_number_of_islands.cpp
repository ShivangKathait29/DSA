class Solution {
public:
    int count = 0;
    int countIslands(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j]!='1'){
            return 0;
        }
        if(grid[i][j]=='1') count = 1;
        grid[i][j] = '0';
        countIslands(grid,i+1,j);
        countIslands(grid,i,j+1);
        countIslands(grid,i-1,j);
        countIslands(grid,i,j-1);
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( countIslands(grid,i,j)) ans++;
            }
        }
       
        return ans;
    }
};