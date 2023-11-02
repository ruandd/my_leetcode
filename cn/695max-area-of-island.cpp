//岛屿的最大面积
//ruan zheng
//2023-11-02 13:31:47

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count;
    bool inArea(vector<vector<int>>& grid, int row, int column) {
        if(row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size())
            return true;
        return false;
    };

    void dfs(vector<vector<int>>& grid, int row, int column) {
        /*越界，返回；
          遇到海洋，返回;
          遇到已经遍历的岛屿，返回*/
        if(!inArea(grid, row, column)) return;
        if(grid[row][column] == 0) return;
        if(grid[row][column] == 2) return;

        grid[row][column] = 2;
        count++;
        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
        dfs(grid, row, column + 1);
        dfs(grid, row, column - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, i, j);
                    maxArea = max(count, maxArea);
                }
            }
        return maxArea;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}