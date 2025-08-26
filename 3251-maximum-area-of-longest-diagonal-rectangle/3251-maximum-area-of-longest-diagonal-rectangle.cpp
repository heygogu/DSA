class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=INT_MIN;
        
        double maxDiagonal=-1.0;
        for(int i=0;i<dimensions.size();i++){
            int first=dimensions[i][0];
            int second=dimensions[i][1];
            double diagonalLength = sqrt((1LL*first*first) + (1LL*second*second));
            
            if(diagonalLength>maxDiagonal){
                maxDiagonal=diagonalLength;
                ans=first*second;
            }else if (diagonalLength == maxDiagonal) {
                ans = max(ans, first*second);
            }
        }

        return ans;
    }
};