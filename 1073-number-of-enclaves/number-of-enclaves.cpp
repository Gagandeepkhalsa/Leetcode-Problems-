class Solution {
private:
    void dfs(vector<vector<int>>& grid , int i , int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j]) return;
        grid[i][j] = 0;
        dfs(grid , i - 1 , j);
        dfs(grid , i , j - 1);
        dfs(grid , i + 1 , j);
        dfs(grid , i , j + 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            if(grid[i][0]) dfs(grid , i , 0);
            if(grid[i][n - 1]) dfs(grid , i , n - 1);
        }
        for(int j = 1; j < n - 1; ++j){
            if(grid[0][j]) dfs(grid , 0 , j);
            if(grid[m - 1][j]) dfs(grid , m - 1 , j);
        }
        int moves = 0;
        for(int i = 1; i < m - 1; ++i){
            for(int j = 1; j < n - 1; ++j){
                if(grid[i][j]) ++moves;
            }
        }
        return moves;
    }
};