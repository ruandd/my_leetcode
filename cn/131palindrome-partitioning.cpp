//分割回文串
//ruan zheng
//2023-07-20 21:36:39

#include <string>
#include <vector>
#include <iostream>

using namespace std;
//这题真不会啊;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*左闭右闭区间*/
    bool ispalindrome(string& s, int beg, int end) {
        for(int i = beg, j = end; i < j; i++, j--)
            if(s[i] != s[j])
                return false;

        return true;
    }

    vector<vector<string>> result;
    vector<string> path;
    void backtracking(string& s, int startIndex) {
        if(startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        /*不可以分割字串，不然size就失效*/
        for(int i = startIndex; i < s.size(); i++) {
            if(ispalindrome(s, startIndex, i)) {
                path.push_back(string(s.begin() + startIndex, s.begin() + i + 1));
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("abbab");
    auto result = s.partition(str);
    cout << "helll";
    return 0;
}