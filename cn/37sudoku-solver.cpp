//解数独
//ruan zheng
//2023-07-27 15:41:10

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 本题代码随想录的思路和以前的不太一样;
 * 在递归的时候并没有传递行列值;
 * 而是行列值从0开始，通过判断是否已经有了数字来跳过当次循环;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // 判断行里是否重复
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) { // 判断列里是否重复
            if (board[j][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val ) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board[i][j] != '.') continue;
                for(char k = '1'; k <= '9'; k++) {
                    if(isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if(backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;   //9个数字都试过了，则失败;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}