class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
      
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // push all 0s in queue and mark them visited too
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            auto [r,c,dist]=q.front(); q.pop();
            
            //need to check the neighbor now
            for (auto [dr, dc] : dirs) {
                int nr=r+dr;
                int nc=c+dc;

                if(nr<0 || nc<0 || nr>=n || nc>=m)continue;
                if(visited[nr][nc]==1)continue;
                

                mat[nr][nc]=dist+1;
                q.push({nr,nc,dist+1});
                visited[nr][nc]=1;
            }
        }

        return mat;
    }
};