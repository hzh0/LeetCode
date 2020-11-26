class Solution {
public:

    bool rowIsValid(vector<vector<char>>& board, int row) {
        int a[10]{0}; 
        for (auto i : board[row]) {
            if (i != '.') {
                a[i-'0']++;
                if (a[i-'0'] > 1) return false;
            }
        }
        return true;
    }

    bool colIsValid(vector<vector<char>>& v, int col) {
        int a[10]{0}; 
        for (auto i = 0; i < 9; ++i) {
            if (v[i][col] != '.') {
                a[v[i][col]-'0']++;
                if (a[v[i][col]-'0']>1) return false;
            }
        }
        return true;
    }

    bool boxIsValid(vector<vector<char>>& v, int row, int col) {
        int a[10]{0};
        for (auto i = row; i < row+3; ++i) {
            for (auto j = col; j < col+3; ++j) {
                if (v[i][j] != '.') {
                    a[v[i][j]-'0']++;
                    if (a[v[i][j]-'0']>1) return false;
                }    
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& v) {
        for (auto i = 0; i < 9; ++i) {
            if (!rowIsValid(v, i) || !colIsValid(v,i)) return false;
        }
        for (auto i = 0; i <= 6; i+=3) {
            for (auto j =0; j <= 6; j+=3) {
                if (!boxIsValid(v,i,j)) return false;
            }
        }
        return true;
    }
};