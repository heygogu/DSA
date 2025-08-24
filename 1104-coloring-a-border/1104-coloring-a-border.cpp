vector<pair<int, int>> result; // store inner cells
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    void solve(vector<vector<int>>& grid, int r, int c, int newColor,
               int orgColor) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] != orgColor) {
            return;
        }

        grid[r][c] = -newColor;

        for (auto [dr, dc] : dirs) {
            solve(grid, r + dr, c + dc, newColor, orgColor);
        }

        // while returning check for inner cells by negating border cells

        if (!(r == 0 || r == grid.size() - 1 || c == 0 ||
              c == grid[0].size() - 1 || grid[r + 1][c] != -newColor ||
              grid[r - 1][c] != -newColor || grid[r][c + 1] != -newColor ||
              grid[r][c - 1] != -newColor)) {
            result.push_back({r, c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int orgColor = grid[row][col];

        if (orgColor == color)
            return grid;
        
        result.clear();

        solve(grid, row, col, color, orgColor);

        // moving internal cells back to original color
        for (auto [row, col] : result) {
            grid[row][col] = orgColor;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};