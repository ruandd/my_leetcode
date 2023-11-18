//轮转数组
//ruan zheng
//2023-11-18 14:23:26

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int len = nums.size();
        reverse(nums.begin(), nums.begin() + len - k);
        reverse(nums.begin() + len - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}