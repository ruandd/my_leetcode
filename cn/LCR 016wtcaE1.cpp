//无重复字符的最长子串
//ruan zheng
//2023-10-13 18:49:16

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slow = 0, fast = 0;
        int cnt = 0;
        int maxLength = INT32_MIN;
        unordered_map<char, int> visited;
        for(; fast < s.size(); fast++) {
            visited[s[fast]]++;
            cnt++;
            /*当有元素超过一个时*/
            while(visited.find(s[fast])->second > 1) {
                visited[s[slow++]]--;
                cnt--;
            }
            maxLength = max(maxLength, cnt);

        }
        return (maxLength == INT32_MIN) ? 0 : maxLength;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("pwwkew");
    s.lengthOfLongestSubstring(str);
    return 0;
}