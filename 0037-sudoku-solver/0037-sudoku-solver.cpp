class Solution {
public:
 bool isSafe(vector<vector<char>>& board,int row,int col,char value){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[row][i]==value){
                return false;
            }
            if(board[i][col]==value){
                return false;
            }
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value){
                return false;
            }

        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char val='1';val<='9';val++){
                        if(isSafe(board,i,j,val)){
                            board[i][j]=val;
                            bool ans=solve(board);
                            if(ans) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};