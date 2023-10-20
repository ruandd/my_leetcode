//最长公共前缀
//ruan zheng
//2023-10-19 10:56:06

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*返回两个给定字符串的最长公共前缀*/
    string LCP(const string& str1, const string& str2) {
        if(str1.size() == 0 || str2.size() == 0) return string();
        int i = 0, j = 0;
        /*结束后，i和j指向不等的位置，已经是开区间了*/
        while( i < str1.size() && j < str2.size() && str1[i] == str2[j]) {
            i++;
            j++;
        }
        return string(str1.begin(), str1.begin() + i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 2) return strs[0];
        /*横向扫描*/
        string prefix = LCP(strs[0], strs[1]);
        for(int i = 2; i < strs.size(); i++) {
            prefix = LCP(prefix, strs[i]);
            if(prefix.size() == 0)
                return string();
        }
        return prefix;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<string> v{"flower", "flow", "flight"};
    s.longestCommonPrefix(v);
    return 0;
}