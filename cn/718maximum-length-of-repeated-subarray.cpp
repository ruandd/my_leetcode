//最长重复子数组
//ruan zheng
//2023-09-28 10:00:52

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int result = 0;
        for(int i = 1; i <= nums1.size(); i++)
            for(int j = 1; j <= nums2.size(); j++) {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = 0;                           /*这行可以删掉，因为已经初始化为0了*/

                if(dp[i][j] > result) result = dp[i][j];
            }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}