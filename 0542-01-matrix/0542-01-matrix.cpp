class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
      
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));

        // push all 0s in queue and mark them visited too
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            auto [r,c,d]=q.front(); q.pop();
            
            //need to check the neighbor now
            for (auto [dr, dc] : dirs) {
                int nr=r+dr;
                int nc=c+dc;

                if(nr<0 || nc<0 || nr>=n || nc>=m)continue;
                if(dist[nr][nc]!=-1)continue;
                
                dist[nr][nc]=d+1;
                q.push({nr,nc,d+1});
                
            }
        }

        return dist;
    }
};