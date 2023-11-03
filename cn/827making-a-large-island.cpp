//最大人工岛
//ruan zheng
//2023-11-02 14:14:15

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

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

    void dfs(vector<vector<int>>& grid, int row, int column, int flag) {
        /*越界，返回
         * 遇到海洋，返回
         * 遇到flag说明已经该岛屿已经访问过，返回*/
        if(!inArea(grid, row, column)) return;
        if(grid[row][column] == 0) return;
        if(grid[row][column] == flag) return;

        grid[row][column] = flag;
        count++;
        dfs(grid, row + 1, column, flag);
        dfs(grid, row - 1, column, flag);
        dfs(grid, row, column + 1, flag);
        dfs(grid, row, column - 1, flag);
    };

    int largestIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        unordered_map<int, int> map;
        /*第一次访问，将不同的连接岛屿做上不同的标记*/
        int flag = 1;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    flag++;
                    dfs(grid, i, j, flag);
                    map[flag] = count;
                }
            }
        /*第二次访问，寻找最大的海洋连接点*/
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {

                }
            }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{1, 2, 3};
    auto t = &*vec.begin();
    return 0;
}