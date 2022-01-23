class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    bool isAllow(vector<vector<char>> grid,int row,int col){
        int m=grid.size(),n=grid[0].size();
        return (row>=0 && col>=0 && row<m && col<n&& grid[row][col]=='1');
    }
    void DFS(vector<vector<char>> &grid,int row,int col){
        grid[row][col]='0';
        if (row<grid.size()-1 && grid[row+1][col]=='1'){
            DFS(grid,row+1,col);
        }
        if (col <grid[0].size()-1 && grid[row][col+1]=='1'){
            DFS(grid,row,col+1);
        }
        if (row>0 && grid[row-1][col]=='1'){
            DFS(grid,row-1,col);
        }
        if (col>0 && grid[row][col-1]=='1'){
            DFS(grid,row,col-1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    result++;
                    DFS(grid, r, c);
                }
            }
        }
        return result;
    }
    
};