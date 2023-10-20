//最后一个单词的长度
//ruan zheng
//2023-10-19 11:22:15

#include <string>
#include <vector>
#include <iostream>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * 当使用双指针时，需要自己考虑区间的开放性;
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;
        /*找到最后一个单词的末尾字符*/
        while(right >= 0 && s[right] == ' ') right--;
        int left = right;
        /*找到最后一个单词开头字符*/
        while(left >=0 && s[left] != ' ') left--;
        /*区间是左开右闭*/
        return right - left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("a");
    s.lengthOfLastWord(str);
    return 0;
}