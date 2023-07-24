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
private:
    vector<vector<string>> result;
    vector<string> path; // 放已经回文的子串
    void backtracking (const string& s, int startIndex) {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if(startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            if(isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            //不是startindex + 1;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("aab");
    auto result = s.partition(str);
    cout << "helll";
    return 0;
}