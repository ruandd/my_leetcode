//最大子数组和
//ruan zheng
//2023-08-22 15:43:43

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT32_MIN;
        for(int startIdx = 0; startIdx < nums.size(); startIdx++) {
            sum += nums[startIdx];
            //先记录，再比较;
            if(sum >= maxSum) {
                maxSum = sum;
            }
            if(sum < 0) {
                sum = 0;
                continue;     //跳过本次循环,直接从下一个元素开始;
            }
        }
        return maxSum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}