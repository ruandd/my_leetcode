//删除字符串中的所有相邻重复项
//ruan zheng
//2023-06-22 13:25:08

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> cvec;
        for(auto c:s) {
            //确保栈非空;
            if(cvec.empty()) cvec.push_back(c);
            else if(c == cvec.back()) cvec.pop_back();
            else cvec.push_back(c);
        }
        return string(cvec.begin(), cvec.end());

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}