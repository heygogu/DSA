class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // put boundary rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '1';
            }
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = '1';
            }
        }

        // put boundary cols
        for (int i = 1; i < n - 1; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '1';
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '1';
            }
        }

        // bfs chalao

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [nr, nc] : dirs) {
                nr = nr + r;
                nc = nc + c;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;
                if (board[nr][nc] != 'O')
                    continue;

                board[nr][nc] = '1';
                q.push({nr, nc});
            }
        }

        // convert all 0s to X and 1s to 0s

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};