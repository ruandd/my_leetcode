//除自身以外数组的乘积
//ruan zheng
//2023-11-24 15:24:23

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lproduct(nums.size(), 1), rproduct(nums.size(), 1);
        for(int i = 0, tmp = 1; i < nums.size(); i++) {
            if(i == 0) continue;
            tmp *= nums[i-1];
            lproduct[i] = tmp;
        }
        for(int i = nums.size() - 1, tmp = 1; i >= 0; i--) {
            if(i == nums.size() - 1) continue;
            tmp *= nums[i+1];
            rproduct[i] = tmp;
        }
        vector<int> ret(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            ret[i] = lproduct[i] * rproduct[i];
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums{1, 2, 3, 4};
    s.productExceptSelf(nums);
    return 0;
}