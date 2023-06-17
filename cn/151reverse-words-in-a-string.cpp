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
    void reverse(vector<char>& s, int left, int right) {
        while(left <= right) {
            auto tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        //用vector，避免需要遍历一次s，才能创建暂存结果的string;
        vector<char> cvec;
        int index = s.size()-1;
        //逆序存放，并去除开头的空格;
        while(s[index] == ' ' && index != 0) --index;
        while(index != -1) {
            //非空格，直接保存;
            if(s[index] != ' ') cvec.push_back(s[index--]);
            //遇到空格且前一个非空格，即单独空格，保存;
            else if(s[index] == ' ' && s[index+1] != ' ') cvec.push_back(s[index--]);
            else index--;
        }
        //加入一个空格，方便后续处理;
        if(cvec[cvec.size()-1] != ' ') cvec.push_back(' ');;
        //对每个单词逆序即可;
        int left = 0, right = 0;
        while(right < cvec.size()) {
            while(cvec[right] != ' ') ++right;
            reverse(cvec, left, right-1);
            left = right + 1;
            right = left;
        }
        return string(cvec.begin(), cvec.end()-1);

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