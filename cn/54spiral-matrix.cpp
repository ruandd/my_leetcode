//螺旋矩阵
//ruan zheng
//2023-10-13 16:35:50

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n, 0);
        /*如果只有一行，直接返回*/
        if(m == 1) return matrix[0];
        /*如果只有一列，则直接返回*/
        if(n == 1) {
            for(int j = 0; j < m; j++)
                res[j] = matrix[j][0];

            return res;
        }

        int startx = 0, starty = 0;
        int loop = max(m, n)/2;
        int offset = 1;
        int midx = n/2, midy = m/2;
        int i, j;
        int idx = 0;
        while(loop--) {
            i = startx;
            j = starty;

            /*从左至右*/
            for(; j < n - offset; j++)
                res[idx++] = matrix[i][j];

            /*从上至下*/
            for(; i < m - offset; i++)
                res[idx++] = matrix[i][j];

            /*从右至左*/
            for(; j > starty; j--)
                res[idx++] = matrix[i][j];

            /*从下至上*/
            for(; i > startx; i--)
                res[idx++] = matrix[i][j];

            startx++;
            starty++;
            offset++;
        }

        if(m % 2 && n % 2 && m==n) {
            res[idx] = matrix[midx][midy];
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> vec{{2, 3, 4}, {5, 6, 7}, {8, 9, 10},
                            {11, 12, 13}, {14, 15, 16}};
    auto ret = s.spiralOrder(vec);
    for(auto i : ret)
        cout << i << " ";

    return 0;
}