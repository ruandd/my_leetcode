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
//        int slen = s.size();
//        int tlen = t.size();
//        if(slen > tlen) return false;
//
//        int i = 0, j = 0;
//        while( i < slen && j < tlen) {
//            if(s[i] == t[j]) {
//                i++;
//                j++;
//            }
//            else {
//                j++;
//            }
//        }
//        return i == slen;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 1; i <= s.size(); i++)
            for(int j = 1; j <= t.size(); j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1];
            }

        return dp[s.size()][t.size()] == s.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main(){
    char a[256] = {0};
    char b[256] = {0};
    string s, t;
    while(std::cin >> s >> t) {
        int len = s.size();
        for(int i = 0; i < len; i++) {
            a[s[i]]++;
            b[t[i]]++;
        }
        for(int i = 0; i < 256; i++)
            if(a[i] != b[i]) {
                cout << -1 << endl;
                return -1;
            }

        int same = longestCommonSubsequence(s, t);
        cout << s.size() - same << endl;
        return s.size() - same;

    }
}