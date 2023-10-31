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
    /*多个数字前导0返回false
      数字大于3位返回false
      数字大于255返回false, 避免产生"1124" < "255"这种情况
      直接字符比较，转成int会溢出
      数字位数不同必须单独比较*/
    bool isValid(const string& s, int beg, int end) {
        if(end != beg && s[beg] == '0') return false;
        auto tmp = s.substr(beg, end - beg + 1);
        if(tmp.size() > 3) return false;
        if(tmp.size() == 1 && tmp < "0" || tmp > "9") return false;
        if(tmp.size() == 2 && tmp < "10" || tmp > "99") return false;
        if(tmp.size() == 3 && tmp > "255") return false;
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
    string str("25525511135");
    s.restoreIpAddresses(str);
    return 0;
}