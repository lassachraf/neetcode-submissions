class Solution {
public:
    bool checkDups(vector<char>& row) {
        std::unordered_set<char> seen;

        for (char num : row) {
            if (num == '.')
                continue;
            if (!seen.insert(num).second) {
                return true; 
            }
        }
        return false;
    }
    bool buildAndCheck(vector<vector<char>>& board, int index) {
        std::vector<char> vec;

        for (int i = 0; i < board.size(); i++)
            vec.push_back(board[i][index]);

        return checkDups(vec);        
    }
    bool check3x3(vector<vector<char>>& board, int rowStart, int rowEnd, int colStart, int colEnd) {
        std::unordered_set<char> seen;
    
        for (int i = rowStart; i < rowEnd; ++i) {
            for (int j = colStart; j < colEnd; ++j) {
                if (board[i][j] == '.')
                    continue;
                char val = board[i][j];
                
                if (seen.count(val))
                    return true;
                seen.insert(val);
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (checkDups(board[i]))
                return false;
        }
        for (int i = 0; i < board.size(); i++) {
            if (buildAndCheck(board, i))
                return false;
        }
        if (check3x3(board, 0, 3, 0, 3) || check3x3(board, 0, 3, 3, 6) || check3x3(board, 0, 3, 6, 9)
            || check3x3(board, 3, 6, 0, 3) || check3x3(board, 3, 6, 3, 6) || check3x3(board, 3, 6, 6, 9)
            || check3x3(board, 6, 9, 0, 3) || check3x3(board, 6, 9, 3, 6) || check3x3(board, 6, 9, 6, 9))
            return false;
        return true;
    }
};
