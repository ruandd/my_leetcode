//最小覆盖子串
//ruan zheng
//2023-10-12 13:08:32

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool cmp(unordered_map<char, int>& ans, unordered_map<char, int>& cnt) {
        for(auto it : ans) {
            if(it.second > cnt[it.first])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> ans;
        unordered_map<char, int> cnt;
        for(auto c : t) {
            ans[c]++;
            cnt[c] = 0;
        }
        int left = 0;
        bool flag = false;
        int minLength = INT32_MAX;
        string ret;
        for(int right = 0; right < s.size(); right++) {
            cnt[s[right]]++;
            while(cmp(ans, cnt)) {
                cnt[s[left]]--;
                left++;
                flag = true;
            }
            if(flag) {
                int len = right - left + 2;
                if(len < minLength) {
                    minLength = len;
                    ret = string(s.begin() + left - 1, s.begin() + right + 1);
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    unordered_map<int, int> m1{{1, 3}, {2, 4}};
    unordered_map<int, int> m2{{1, 5}, {2, 4}};
    return 0;
}