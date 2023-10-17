//三数之和
//ruan zheng
//2023-06-15 09:26:43

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
 * 本题要求返回和为0的三元组，且要求i != j, j != k, i != k;
 * 那么必须要求三个元素的位置是有序的，就可以避免相等;
 * 但这样针对[-1, -1, 0, 1]和[0, 0, 0, 0]样例没法处理，会给出重复答案;
 * 需要提前排序，发现重复元素就跳过该循环来去重;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> pos;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            pos[nums[i]] = i;

        for(int i = 0; i < nums.size(); i++) {
            /*去重*/
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < nums.size(); j++) {
                /*去重*/
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                auto t = pos.find(0-nums[i]-nums[j]);
                if(t != pos.end() && t->second > j)
                    result.push_back(vector<int>{nums[i], nums[j], nums[t->second]});
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