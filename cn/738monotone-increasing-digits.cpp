//单调递增的数字
//ruan zheng
//2023-09-05 09:13:02

#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <stack>

using namespace std;
/*
 * 1. 一旦出现某一位比前面下，该位置右边所有都需要赋值为9;
 * 2. 善用to_string和stoi;
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        //flag用来标记赋值9从哪里开始;
        //防止第二个for循环在flag没有被赋值的情况下执行;
        int flag = strNum.size();
        for(int i = strNum.size() - 1; i > 0; i--) {
            if(strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for(int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}