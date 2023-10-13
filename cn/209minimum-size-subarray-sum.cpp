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
        int i = 0, sum = 0;
        int subLength = 0;
        int result = INT32_MAX;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            subLength++;
            while(sum >= target) {
                if(subLength < result)
                    result = subLength;
                sum -= nums[i++];
                subLength--;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{2, 3, 1, 2, 4, 3};
    s.minSubArrayLen(7, vec);
    return 0;
}