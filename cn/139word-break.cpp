//单词拆分
//ruan zheng
//2023-09-19 13:04:51

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*本题是完全背包求价值问题（这里的价值和重量一样),但是是排列问题*/
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<unsigned long> dp(s.size() + 1, 0);
        /*先遍历容量，再遍历物品*/
        for(int j = 0; j <= s.size(); j++) {
            for(int i = 0; i < wordDict.size(); i++) {
                if(j >= wordDict[i].size()) {
                    if(wordDict[i] == string(s.begin() + j - wordDict[i].size(), s.begin() + j))
                        dp[j] = max(dp[j], dp[j - wordDict[i].size()] + wordDict[i].size());
                }
            }
        }
        return dp[s.size()] == s.size();

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}