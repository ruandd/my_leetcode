//找出字符串中第一个匹配项的下标
//ruan zheng
//2023-06-19 18:18:48

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 没太看懂;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*前缀[0, j],后缀[1, i]*/
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while(j > 0 && s[j] != s[i])
                j = next[j-1];
            if(s[i] == s[j])
                j++;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        /*i是匹配文本串的下标，j是模式串的下标*/
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {
            /*不相等时候，模式串j回溯*/
            while(j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            /*相等则递增模式串j的下标*/
            if(haystack[i] == needle[j])
                j++;
            /*模式串匹配结束*/
            if(j == needle.size())
                return (i - needle.size() + 1);
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}