//验证回文串
//ruan zheng
//2023-10-19 13:08:08

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 必须熟悉常见的字符串函数;
 * reverse()函数不返回值;
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++) {
            if(isalnum(s[fast])) {
               s[slow++] = tolower(s[fast]);
            }
        }
        s.resize(slow);
        string t = s;
        reverse(s.begin(), s.end());
        return t == s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}