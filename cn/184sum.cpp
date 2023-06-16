//四数之和
//ruan zheng
//2023-06-15 10:33:04

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //开始遍历;
        for(int i=0; i<nums.size(); i++) {
            //对nums[i]去重;
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j=i+1; j<nums.size(); j++) {
                //对nums[j]去重;
                if(j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int left = j+1;
                int right =  nums.size()-1;
                while(left < right) {
                    if( (long)nums[left] + nums[right] + nums[i] + nums[j] > target) right--;
                    else if( (long)nums[left] + nums[right] + nums[i] + nums[j] < target) left++;
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        left++;
                        right--;
                    }
                }
            }

        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}