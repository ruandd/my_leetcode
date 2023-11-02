//岛屿的周长
//ruan zheng
//2023-11-02 12:59:12

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumArea = 0;
    bool inArea(vector<vector<int>>& grid, int row, int column) {
        if(row >= 0 && row < grid.size() && column >=0 && column < grid[0].size())
            return true;
        return false;
    }

    /*格子值为0为海洋，1为岛屿，2为已经遍历过的岛屿*/
    int dfs(vector<vector<int>>& grid, int row, int column) {
        /*超出网格范围*/
        if(!inArea(grid, row, column)) return 1;
        /*遇到海洋*/
        if(grid[row][column] == 0) return 1;
        /*遇到已经遍历过的岛屿*/
        if(grid[row][column] == 2) return 0;

        grid[row][column] = 2;
        return dfs(grid, row + 1, column) +
        dfs(grid, row, column + 1) +
        dfs(grid, row - 1, column) +
        dfs(grid, row , column - 1);

    };
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}