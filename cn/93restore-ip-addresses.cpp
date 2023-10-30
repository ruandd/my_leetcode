//复原 IP 地址
//ruan zheng
//2023-07-24 20:29:02

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(const string& s, int beg, int end) {
        if(end != beg && s[beg] == '0') return false;
        auto tmp = string(s.begin() + beg, s.end() + end + 1);
        /*不能先转化为整型再去比较，会溢出，需要直接对字符串进行比较*/
        if(tmp > string("255")) return false;
        return true;
    }

    vector<string> result;
    string path;
    /*记录字节数*/
    int num = 0;
    void backtracking(const string& s, int startIndex) {
        if(num == 4 && startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        if(num == 4 && startIndex < s.size()) return;
        if(num > 4 || startIndex >= s.size()) return;



        for(int i = startIndex; i < s.size(); i++) {
            if(isValid(s, startIndex, i)) {
                num++;
                /*如果是空串，仅插入一个字节的地址*/
                if(path.empty()) {
                    path += s.substr(startIndex, i - startIndex + 1);
                }
                    /*否则插入一个.和一个字节的有效地址*/
                else {
                    path += "." + s.substr(startIndex, i - startIndex + 1);
                }
            }
                /*跳过本次选取*/
            else {
                continue;
            }
            backtracking(s, i + 1);
            /*回溯*/
            num--;
            if(path.find(".") == string::npos) {
                path = string();
            }
            else {
                int len = path.size() - (i - startIndex + 2);
                path.resize(len);
            }
        }
    };
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("255123451243123");
    s.restoreIpAddresses(str);
    return 0;
}