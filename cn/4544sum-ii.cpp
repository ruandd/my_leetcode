//四数相加 II
//ruan zheng
//2023-06-14 13:59:47

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
/*
 * 本题切记，求得是组合个数，不求位置。
 * 假设cnt中-1有t个,当i+j为1时，应该是result += cnt[-1];
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> cnt;
        int result = 0;
        int n = nums1.size();
        for(auto i: nums1)
            for(auto j: nums2)
                cnt[i+j]++;

        for(auto i: nums3)
            for(auto j: nums4) {
                auto t = cnt.find(0 - i - j);
                if(t != cnt.end())
                    result += t->second;
            }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> v1{-1, -1}, v2{-1, 1}, v3{-1, 1}, v4{1, -1};
    s.fourSumCount(v1, v2, v3, v4);
    return 0;
}