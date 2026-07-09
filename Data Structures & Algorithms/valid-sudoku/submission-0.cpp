class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char> > rows(9, unordered_set<char>());
        vector<unordered_set<char> > cols(9, unordered_set<char>());
        vector<unordered_set<char> > boxes(9, unordered_set<char>());
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                char cur = board[row][col];
                int boxIndex = (row / 3) * 3 + (col / 3);
                if(cur < '1' || cur > '9') continue;
                if(rows[row].count(cur) || cols[col].count(cur) ||
                boxes[boxIndex].count(cur)) return false;
                rows[row].insert(cur);
                cols[col].insert(cur);
                boxes[boxIndex].insert(cur);
            }
        }
        return true;
    }
};
