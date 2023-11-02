//岛屿数量
//ruan zheng
//2023-11-02 12:47:38

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count = 0;
    bool inArea(vector<vector<char>>& grid, int row, int column) {
        if(row >= 0 && row < grid.size() && column >=0 && column < grid[0].size())
            return true;
        return false;
    }

    /*格子值为0为海洋，1为岛屿，2为已经遍历过的岛屿*/
    void dfs(vector<vector<char>>& grid, int row, int column) {
        if(!inArea(grid, row, column)) return;
        if(grid[row][column] != '1') return;

        grid[row][column] = '2';
        dfs(grid, row + 1, column);
        dfs(grid, row, column + 1);
        dfs(grid, row - 1, column);
        dfs(grid, row , column - 1);

    };
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<char>> vec{{'1', '1', '1', '1'}};
    return 0;
}