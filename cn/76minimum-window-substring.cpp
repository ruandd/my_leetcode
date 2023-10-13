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
    string minWindow(string s, string t) {
        int leftBorder, rightBorder;                         /*记录最后的结果*/
        int left = 0;                                        /*左指针*/
        int length = INT32_MAX;
        unordered_map<char, int> map_t;
        unordered_map<char, int> map_search;
        for(auto c : t)
            map_t[c]++;

        for(int right = 0; right < s.size(); right++) {
            if(map_t.find(s[right]) != map_t.end())
                map_search[right]++;                         /*只把t中出现的字符加入到map中*/

            if(map_t == map_search) {                          /*找到区间，开始收缩无用的字符*/
                while(map_search.find(s[left++]) == map_search.end());
                //找到最小区间;
                if((right - left + 1) < length) {
                    leftBorder = left;
                    rightBorder = right;
                    length = right - left + 1;
                }
            }
            /*再次收缩left，找下一个区间*/
            while(map_search.find(s[left]) == map_search.end() ||
                    (map_search.find(s[left])->second-- != 1))
                left++;
            left++;
        }

        return s.substr(leftBorder, length);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    unordered_map<int, int> m1{{1, 3}, {2, 4}};
    unordered_map<int, int> m2{{1, 5}, {2, 4}};
    return 0;
}