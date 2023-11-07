//字母异位词分组
//ruan zheng
//2023-11-06 11:12:00

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for(string str: strs) {
            auto tmp = str;
            sort(str.begin(), str.end());
            map[str].push_back(tmp);
        }
        for(auto t: map) {
            result.push_back(t.second);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ret = s.groupAnagrams(v);
    return 0;
}