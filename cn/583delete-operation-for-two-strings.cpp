//两个字符串的删除操作
//ruan zheng
//2023-10-01 17:17:27

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++) dp[0][j] = j;

        for(int i = 1; i <= word1.size(); i++)
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1] != word2[j-1])
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                else
                    dp[i][j] = dp[i-1][j-1];
            }

        return dp[word1.size()][word2.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}