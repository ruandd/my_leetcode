//替换空格
//ruan zheng
//2023-06-17 14:36:36

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        vector<char> cvec;
        for(auto c: s) {
            if(c == ' ') {
                cvec.push_back('%');
                cvec.push_back('2');
                cvec.push_back('0');
            }
            else {
                cvec.push_back(c);
            }
        }
        return string(cvec.begin(), cvec.end());

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}