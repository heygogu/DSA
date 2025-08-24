vector<pair<int,int>>dirs={
    {-1,0},{1,0},{0,-1},{0,1}
};
class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int color,int orgColor){

        if((sr<0||sr>=image.size() || sc<0 || sc>=image[0].size()))return;
        if(image[sr][sc]!=orgColor)return;

        //go in all four directions after changing the color
        image[sr][sc]=color;

        for(auto [row,col]:dirs){
            solve(image,sr+row,sc+col,color,orgColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor=image[sr][sc];

        if(orgColor==color)return image;

        solve(image,sr,sc,color,orgColor);

        return image;
    }
};