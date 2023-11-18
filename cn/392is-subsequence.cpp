//判断子序列
//ruan zheng
//2023-09-28 14:13:24

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        cout << dp[m][n] << endl;
        return dp[m][n] == m;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main(){
    class Solution s;
    string s1("abc");
    string t("ahbgdc");
    auto ret = s.isSubsequence(s1, t);
    cout << ret << endl;
}
