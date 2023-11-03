//飞地的数量
//ruan zheng
//2023-11-03 10:47:04

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count;
    bool inArea(vector<vector<int>>& grid, int row, int column) {
        if(row < 0 || row >= grid.size() || column < 0 || column > grid[0].size()) return false;
        return true;
    };
    /*当越界则返回false,其它情况返回true*/
    bool dfs(vector<vector<int>>& grid, int row, int column) {
        if(!inArea(grid, row, column)) return false;
        if(grid[row][column] == 2) return true;
        if(grid[row][column] == 0) return true;

        grid[row][column] = 2;
        count++;
        bool ans1 = dfs(grid, row + 1, column);
        bool ans2 = dfs(grid, row, column + 1);
        bool ans3 = dfs(grid, row - 1, column);
        bool ans4 = dfs(grid, row, column - 1);
        return ans1 && ans2 && ans3 && ans4;
   }
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size() == 1 || grid[0].size() == 1) return 0;
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    bool ans = dfs(grid, i, j);
                    if(ans) sum += count;
                }
            }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> vec{{0,0,0,1,1,1,0,1,0,0},
                            {1,1,0,0,0,1,0,1,1,1},
                            {0,0,0,1,1,1,0,1,0,0},
                            {0,1,1,0,0,0,1,0,1,0},
                            {0,1,1,1,1,1,0,0,1,0},
                            {0,0,1,0,1,1,1,1,0,1},
                            {0,1,1,0,0,0,1,1,1,1},
                            {0,0,1,0,0,1,0,1,0,1},
                            {1,0,1,0,1,1,0,0,0,0},
                            {0,0,0,0,1,1,0,0,0,1}};
    vector<vector<int>> v2{{0},
                          {1},
                          {1},
                          {0},
                          {0}};
    auto ret = s.numEnclaves(v2);
    cout << ret;
    return 0;
}