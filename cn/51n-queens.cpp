//N 皇后
//ruan zheng
//2023-07-26 10:55:28

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<pair<int, int>> selectPos;

    bool isValidPos(int row, int clu) {
        bool flag = true;
        for(auto pos: selectPos) {
            if(abs(row - pos.first) == abs(clu - pos.second)) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    string generatePos(int row, int clu, int n) {
        string str(n, '.');
        str[clu] = 'Q';
        return str;
    }

    void backtracking(int n, vector<bool>& used, int row) {
        if(path.size() == n) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(used[i] == true) continue;
            if(!isValidPos(row, i)) continue;

            used[i] = true;
            path.push_back(generatePos(row, i, n));
            //记录已经选过的位置;
            selectPos.push_back(std::pair<int, int>{row, i});
            backtracking(n, used, row + 1);
            selectPos.pop_back();
            path.pop_back();
            used[i] = false;
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> used(n, false);
        backtracking(n,used, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.solveNQueens(4);
    return 0;
}