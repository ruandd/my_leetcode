//有效的括号
//ruan zheng
//2023-06-21 17:57:57

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            //判空非常重要，防止出现['}]这种输入;
            if(st.empty()) st.push(c);
            else if(c == ')' && st.top() == '(')
                st.pop();
            else if(c == '}' && st.top() == '{')
                st.pop();
            else if(c == ']' && st.top() == '[')
                st.pop();
            else
                st.push(c);
        }
        return st.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}