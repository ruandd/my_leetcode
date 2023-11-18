//矩阵置零
//ruan zheng
//2023-11-18 14:23:03

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void doSetZero(int r, int c, vector<vector<int>>& m) {
        for(int i = 0; i < m.size(); i++) m[i][c] = 0;
        for(int j = 0; j < m[0].size(); j++) m[r][j] = 0;
    };
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0)
                    vec.push_back(pair<int, int>(i, j));
            }
        for(auto t : vec) {
            doSetZero(t.first, t.second, matrix);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}