//最长公共子序列
//ruan zheng
//2023-09-28 10:33:46

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*多一行一列，方便迭代*/
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int result = 0;
        for(int i = 1; i <= text1.size(); i++)
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;                /*记住dp[i][j]的定义，是以[i][j]为结尾！！！*/
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if(dp[i][j] > result) result = dp[i][j];
            }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string s1 = "abc";
    string s2 = "def";
    auto ret = s.longestCommonSubsequence(s1, s2);
    return 0;
}