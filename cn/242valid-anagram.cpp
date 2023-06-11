//有效的字母异位词
//ruan zheng
//2023-06-11 09:53:03

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(int i=0; i<s.size(); i++) {
            int index = s[i]%26;
            hash1[index] += 1;
        }
        for(int i=0; i<t.size(); i++) {
            int index = t[i]%26;
            hash2[index] += 1;
        }
        return hash1 == hash2;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    s.isAnagram("aaaab", "bbbba");
    return 0;
}