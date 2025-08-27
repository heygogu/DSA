vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    vector<vector<int>> bfs (queue<pair<int,int>>&q,vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        

        while(!q.empty()){
            auto [r,c]=q.front(); 
            q.pop();
            visited[r][c]=1;

            for(auto [row,col]:dirs){
                int nr=r+row;
                int nc=c+col;

                if(nr<0 || nc<0 || nr>=n || nc>=m)continue;
                if(heights[nr][nc]<heights[r][c]) continue;
                if(visited[nr][nc]==1) continue;

                visited[nr][nc]=1;
                q.push({nr,nc});
            }
        }

        return visited;

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>answer;
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>>pacific(n,vector<int>(m,0));

        //inserting the nodes in atlantic
        queue<pair<int,int>>pacificbfs;
        queue<pair<int,int>>atlanticbfs;
        for(int i=0;i<n;i++){
            pacificbfs.push({i,0});
            atlanticbfs.push({i,m-1});
        }

        for(int j=1;j<m;j++){
            pacificbfs.push({0,j});
        }

        for(int j=0;j<m-1;j++){
            atlanticbfs.push({n-1,j});
        }
        
        pacific=bfs(pacificbfs,heights);
        atlantic=bfs(atlanticbfs,heights);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    answer.push_back({i,j});
                }
            }
        }
     

        return answer;
    }
};