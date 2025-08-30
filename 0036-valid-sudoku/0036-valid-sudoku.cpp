
class Solution {
public:
   bool checkDuplicateInRow(vector<vector<char>>&board, int row,int col){
        for(int c=0;c<9;c++){
            if(c==col) continue;
            if(board[row][c]==board[row][col]){
                return true;
            }
        }
        return false;
   }
   bool checkDuplicateInCol(vector<vector<char>>&board, int row,int col){
       for(int r=0;r<9;r++){
          if(r==row) continue;
          if(board[r][col]==board[row][col]){
            return true;
          }
       }
       return false;
   }

   bool checkBox(vector<vector<char>>& board, int row, int col) {
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (r == row && c == col) continue; 
            if (board[r][c] == board[row][col]) {
                return true; 
            }
        }
    }
    return false; 
}
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.')continue;

                //if I am here I have got the element
                
                //check the current row
                bool rowAns = checkDuplicateInRow(board,r,c);
                if(rowAns) return false;
                
                //check the current col
                bool colAns= checkDuplicateInCol(board,r,c);
                if(colAns) return false;

                //check the current box 
                bool boxAns=checkBox(board,r,c);
                if(boxAns) return false;
                
            }
        }

        return true;
    }
};