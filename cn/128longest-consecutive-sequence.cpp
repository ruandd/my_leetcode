//最长连续序列
//ruan zheng
//2023-11-06 12:48:30

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int length = 0;
        int longestLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            /*如果nums[i] - 1不再集合中，说明它是连续序列的第一个*/
            if(set.count(nums[i] - 1) != 1) {
                length = 1;
                int start = nums[i];
                int j = 1;
                while(set.count(start + j) == 1) {
                    length++;
                    j++;
                }
                longestLength = max(longestLength, length);
            }
        }
        return longestLength;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> v{100, 4, 200, 1, 3, 2};
    s.longestConsecutive(v);

    return 0;
}