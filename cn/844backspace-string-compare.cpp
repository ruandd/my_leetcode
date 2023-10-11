//比较含退格的字符串
//ruan zheng
//2023-06-01 20:37:31

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
 * 出栈前一定要判断是否为空
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
//        vector<char> v1, v2;
//        for(auto &c: s) {
//            if(c != '#') v1.push_back(c);
//            else if(!v1.empty()) v1.pop_back();
//        }
//        for(auto &c: t) {
//            if(c != '#') v2.push_back(c);
//            else if(!v2.empty()) v2.pop_back();
//        }
//        return v1==v2;
//    }
        int idx1 = s.size() - 1, idx2 = t.size() - 1;
        while (idx1 >= 0 && idx2 >= 0) {
            if (s[idx1] != '#' && t[idx2] != '#' && s[idx1] == t[idx2]) {
                idx1--;
                idx2--;
            } else if (s[idx1] == '#' && t[idx2] == '#') {
                int cnt1 = 0, cnt2 = 0;
                while (s[idx1] == '#') {
                    cnt1++;
                    idx1--;
                }
                while (t[idx2] == '#') {
                    cnt2++;
                    idx2--;
                }
                idx1 -= cnt1;
                idx2 -= cnt2;
            } else
                return false;
        }
        return (idx1 == 0 && idx2 == 0) ? true : false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.backspaceCompare("ab#c", "ad#c");
    cout << ret;
    return 0;
}