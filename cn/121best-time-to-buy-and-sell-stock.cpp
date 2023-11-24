//买卖股票的最佳时机
//ruan zheng
//2023-09-21 10:22:56

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum = prices[0];
        int maxNum = prices[prices.size() - 1];
        for(int i = 1, j = prices.size() - 2; i <= j; i++, j--)  {
            minNum = min(minNum, prices[i]);
            maxNum = max(maxNum, prices[j]);
        }
        return maxNum - minNum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main(){
    vector<int> nums{7, 1, 5, 3, 6, 4};
    Solution s;
    int ret = s.maxProfit(nums);
}