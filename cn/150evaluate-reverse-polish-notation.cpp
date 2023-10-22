//逆波兰表达式求值
//ruan zheng
//2023-06-22 13:36:52

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;
/*
 * 1. 注意运算范围;
 * 2. string转数字的函数，包括stoi,stol,stof,stod;
 * 3. 为了方便计算，栈应该是long int型;
 * 4. 先统一判断是否为符号，是则取出栈顶两个元素，再判断具体符号和操作，避免冗余操作;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*反向判断，是符号就操作，数字直接入栈*/
    int evalRPN(vector<string>& tokens) {
        stack<long int> st;
        long int num1, num2;
        for(auto str: tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                if(str == "+")
                    st.push(num1+num2);
                if(str == "-")
                    st.push(num2-num1);
                if(str == "*")
                    st.push(num1*num2);
                if(str == "/")
                    st.push(num2/num1);
            }
            else {
                st.push(stol(str));
            }
        }
        return st.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}