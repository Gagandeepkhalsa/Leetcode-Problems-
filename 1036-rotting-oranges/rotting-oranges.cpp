class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();

    auto isNeighborRotten = [&](int i, int j, const vector<vector<int>>& grid) {
      for (const auto& [dx, dy] : kDirs) {
        const int r = i + dx;
        const int c = j + dy;
        if (r < 0 || r == m || c < 0 || c == n)
          continue;
        if (grid[r][c] == 2)
          return true;
      }
      return false;
    };

    int ans = 0;

    while (true) {
      vector<vector<int>> nextGrid(m, vector<int>(n));
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1) {  
           
            if (isNeighborRotten(i, j, grid))
              nextGrid[i][j] = 2;
            else
              nextGrid[i][j] = 1;
          } else if (grid[i][j] == 2) {  
            nextGrid[i][j] = 2;          
          }
      if (nextGrid == grid)
        break;
      grid = nextGrid;
      ++ans;
    }

    return any_of(grid.begin(), grid.end(),
                  [&](vector<int>& row) {
      return ranges::any_of(row, [&](int orange) { return orange == 1; });
    })
               ? -1
               : ans;
  }
};
