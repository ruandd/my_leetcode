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
    //映射数组
    const string letterMap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
    vector<string> result;
    string path;
    void backtracking(string& digits, int smartIdx) {
        if(path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        for(int i = smartIdx; i < digits.size(); i++) {
            //取出映射的数组;
            int tmp;
            std::stringstream str2digit;
            str2digit << digits[i];
            str2digit >> tmp;
            string letters = letterMap[tmp];
            for(int j = 0; j < letters.size(); j++) {
                path.push_back(letters[j]);
                //进入递归;
                backtracking(digits, i + 1);
                path.pop_back();  //回溯;
            }

        }
    }
    vector<string> letterCombinations(string digits) {
        //空需要单独处理;
        //因为需要返回[]，而不是[""];
        if(digits.empty()) return result;
        backtracking(digits, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string d("23");
    s.letterCombinations(d);

    return 0;
}