//左旋转字符串
//ruan zheng
//2023-06-18 10:46:21

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 * 每次循环移动一个首元素到末尾;
 * 移动n次即可;
 * 时间复杂度O(kn),空间复杂度O(1);
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int k = 0; k < n; k++) {
            auto tmp = s[0];
            for(int i = 0; i < s.size()-1; i++) {
                s[i] = s[i+1];
            }
            s[s.size()-1] = tmp;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}