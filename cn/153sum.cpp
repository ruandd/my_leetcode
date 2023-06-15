//三数之和
//ruan zheng
//2023-06-15 09:26:43

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //必须先排序;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            //首元素大于0，不可能找到符合条件的三元组，跳过;
            if(nums[i] > 0) return result;

            //对a进行去重;
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            //因为不能重复元素，所以left不可以等于right
            while(left < right) {
                if(nums[i]+nums[left]+nums[right] > 0) right--;
                else if(nums[i]+nums[left]+nums[right] < 0) left++;
                else {
                    //等于0，则保存三元组;
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    //等于0也要记得移动指针;
                    left++;
                    right--;
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