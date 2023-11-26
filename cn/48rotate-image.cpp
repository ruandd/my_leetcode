//旋转图像
//ruan zheng
//2023-11-25 13:13:15

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*外层循环控制圈数，内层循环控制交换次数*/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
            for(int j = 0; j < (n+1)/2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(vec);
    return 0;
}