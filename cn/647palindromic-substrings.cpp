//回文子串
//ruan zheng
//2023-10-01 19:29:04

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for(int i = s.size() - 1; i >= 0; i--)
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 1) {
                        result++;
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]) {
                        result++;
                        dp[i][j] = true;
                    }
                }
            }

        return  result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}