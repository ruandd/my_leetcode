//电话号码的字母组合
//ruan zheng
//2023-07-19 16:14:49

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    unordered_map<char, string> hash{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                     {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> result;
    string path;
    void backtracking(string digits, int startIndex) {
        if(path.size() == digits.size()) {
            result.push_back(path);
            return;
        }
        /*本题也是一个组合问题，只不过多了一层映射*/
        for(int i = startIndex; i < digits.size(); i++) {
            for(auto c : hash[digits[i]]) {
                path += c;
                backtracking(digits, i + 1);
                path.erase(path.begin() + path.size() - 1);
            }
        }
    };
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>{};
        backtracking(digits, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;


    return 0;
}