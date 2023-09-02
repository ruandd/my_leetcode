//K 次取反后最大化的数组和
//ruan zheng
//2023-08-30 09:57:11

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * 先把绝对值大的负数处理完;
 * 再对绝对值最小的正数反复处理;
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2 == 1) nums[nums.size() - 1] *= -1;
        int result = 0;
        for(int i : nums) result += i;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}