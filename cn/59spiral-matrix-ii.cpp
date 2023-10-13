//螺旋矩阵 II
//ruan zheng
//2023-10-13 16:21:04

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int loop = n/2;
        int mid = n/2;
        int offset = 1;
        int i, j;
        int count = 1;
        while(loop--) {
            i = startx, j = starty;

            /*从左至右*/
            for(; j < n - offset; j++)
                result[i][j] = count++;

            /*从上至下*/
            for(; i < n - offset; i++)
                result[i][j] = count++;

            /*从右至左*/
            for(; j > starty; j--)
                result[i][j] = count++;

            /*从下至上*/
            for(; i > startx; i--)
                result[i][j] = count++;

            startx++;
            starty++;
            offset++;

        }
        if(n % 2 == 1)
            result[mid][mid] = count;

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}