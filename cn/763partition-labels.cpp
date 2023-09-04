//划分字母区间
//ruan zheng
//2023-09-04 10:07:42

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
/*
 * 切记切记size_t是无符号数，不能和int型比较;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for(int i = s.size()-1; i >= 0; i--) {
            if(m.find(s[i]) == m.end()) {
                //最远出现位置;
                m[s[i]] = i;
            }
        }
        vector<int> result;
        int count = 0;
        int maxPos = INT32_MIN;
        for(int j = 0; j < s.size(); j++) {
            count++;
            if(m.find(s[j])->second > maxPos)
                maxPos = m.find(s[j])->second;
            if(maxPos == j) {
                result.push_back(count);
                count = 0;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("ababcbacadefegdehijhklij");
    s.partitionLabels(str);

    return 0;
}