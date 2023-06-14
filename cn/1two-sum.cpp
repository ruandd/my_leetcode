//两数之和
//ruan zheng
//2023-06-14 13:17:17

#include<string>
#include<vector>
#include<iostream>
#include <map>

using namespace std;

/*
 * 1.在存储map的时候，不要搞错顺序，find查找的是键;
 * 2.检查查找到的值，避免返回重复索引;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        map<int, int> nums_map;
        //把nums数组的下标和值存储到map中;
        for (int index = 0; index < nums.size(); index++)
            nums_map.insert({nums[index], index});
        for (int index = 0; index < nums.size(); index++) {
            auto iter = nums_map.find((target - nums[index]));
            if (iter != nums_map.end() && (*iter).second != index)
                return {index, (*iter).second};
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.twoSum({2, 7, 11, 15}, 9);
    return 0;
}