//比较含退格的字符串
//ruan zheng
//2023-06-01 20:37:31

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
 * 出栈前一定要判断是否为空
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1, v2;
        for(auto &c: s) {
            if(c != '#') v1.push_back(c);
            else if(!v1.empty()) v1.pop_back();
        }
        for(auto &c: t) {
            if(c != '#') v2.push_back(c);
            else if(!v2.empty()) v2.pop_back();
        }
        return v1==v2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.backspaceCompare("ab#c", "abd#f#c");
    cout << ret;
    return 0;
}