vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if(dp[i][j]!=0) return dp[i][j];

        int best = 1; 
        for (auto [dr, dc] : dirs) {
            int nr = i + dr, nc = j + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (matrix[nr][nc] > matrix[i][j]) {
                best = max(best, 1 + solve(nr, nc, matrix));
            }
        }
        return dp[i][j]=best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int maxi = 0;
        
        dp.resize(n,vector<int>(m,0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, solve(i, j, matrix));
            }
        }
        return maxi;
    }
};
