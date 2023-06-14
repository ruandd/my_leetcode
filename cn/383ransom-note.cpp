//赎金信
//ruan zheng
//2023-06-14 15:07:02

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //定义哈希数组记录magazine中出现的字符
        int hash[26] = {0};
        for(auto c: magazine)
            hash[(c%26)]++;
        for(auto c: ransomNote)
            hash[(c%26)]--;
        for(int i=0; i<26; i++)
            if(hash[i] < 0) return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}