vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // find all cells where there is 2

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int minutes = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        

        while (!q.empty()) {
            int sz=q.size();
            bool isRotten=false;
            for (int k = 0; k < sz; k++) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [row, col] : dirs) {
                    int newRow = i + row;
                    int newCol = j + col;
                    // check if not out of bounds
                    if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m)
                        continue;
                    if (grid[newRow][newCol] == 0 || grid[newRow][newCol] == 2)
                        continue;

                    // means not rotten
                    grid[newRow][newCol] = 2;
                    q.push({newRow, newCol});
                    isRotten=true;
                }
            }

            if(isRotten)minutes++;
        }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }

            return minutes;
        }
    };