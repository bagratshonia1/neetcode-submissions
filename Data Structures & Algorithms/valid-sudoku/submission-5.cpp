class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool rows[9][10]{};
       bool cols[9][10]{};
       bool boxes[9][10]{};
       for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[row].size(); col++){
            int boxInd = (row / 3) * 3 + (col / 3);
            char current = board[row][col];
            if(board[row][col] == '.') continue;
            int num = current - '0';
            if(rows[row][num] || cols[col][num] || boxes[boxInd][num]){
                return false;
            }
            rows[row][num] = true;
            cols[col][num] = true;
            boxes[boxInd][num] = true;
        }
       }
       return true;
    }
};