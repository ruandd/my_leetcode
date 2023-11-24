//杨辉三角
//ruan zheng
//2023-11-24 15:23:44

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back(vector<int>{1});
        if(numRows == 1) return result;
        result.push_back(vector<int>{1, 1});
        for(int i = 2; i < numRows; i++) {
            vector<int> tmp{1};
            vector<int> pre = result[i-1];
            for(int j = 1; j < pre.size(); j++) {
                tmp.push_back(pre[j] + pre[j-1]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}