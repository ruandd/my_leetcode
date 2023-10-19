//反转字符串中的单词
//ruan zheng
//2023-06-17 15:01:58

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                /*为什么不是s[++slow], 因为一开始slow指向的也是无效字符，换句话说，它指向新字符数组的
                 * 下一个位置*/
                if(slow != 0) s[slow++] = ' ';
                while(i < s.size() && s[i] != ' ')
                    s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }

    void reverse(string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        /*去除多余的空格并翻转整个字符串*/
        removeExtraSpaces(s);
        reverse(s, 0, s.size() -1);
        int left = 0, right = 0;
        while(right < s.size()) {
            if(s[right] != ' ') right++;
            else {
                reverse(s, left, right - 1);
                left = right + 1;
                right = left;
            }
        }
        reverse(s, left, right - 1);
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.reverseWords("  hello world  ");
    for(auto c: ret)
        cout << c;
    return 0;
}