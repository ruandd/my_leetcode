//长度最小的子数组
//ruan zheng
//2023-06-03 21:24:00

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}