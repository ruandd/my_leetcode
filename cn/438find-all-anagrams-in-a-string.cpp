//找到字符串中所有字母异位词
//ruan zheng
//2023-10-16 12:39:33

#include <string>
#include <vector>
#include <iostream>
#include <un

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cntp(26, 0);
        vector<int> cnt(26, 0);
        vector<int> result;
        for(auto c: p)
            cntp[c%26]++;
        int left = 0, right = 0;
        /*初始化遍历*/
        while(right < p.size()) {
            cnt[s[right++]%26]++;
        }
        if(cnt == cntp) result.push_back(left);

        /*后续移动滑动窗口*/
        while(right < s.size()) {
            cnt[s[left++]%26]--;
            cnt[s[right++]%26]++;
            if(cnt == cntp) result.push_back(left);
        }
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string t("cbaebabacd");
    string p("abc");
    s.findAnagrams(t, p);
    return 0;
}