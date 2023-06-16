//反转字符串 II
//ruan zheng
//2023-06-16 15:23:06

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 关键是看懂题意；
 * 当剩下字符数大于k且小于2k的时候，k个之后的字符是固定不变的;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverse(string& s, int beg, int end) {
        while(beg <= end) {
            auto tmp = s[beg];
            s[beg] = s[end];
            s[end] = tmp;
            beg++;
            end--;
        }
    };

    string reverseStr(string s, int k) {
        int size = s.size();
        //index为遍历处理的指针
        int index = 0;
        while(index < size) {
            if(index + k > size) {
                reverse(s, index, size-1);
                return s;
            }
//            else if(index + k < size && index + k + k > size) {
//                reverse(s, index, index + k - 1);
//                index = index + k + k;
//            }
            else {
                reverse(s, index, index + k - 1);
                index = index + k + k;
            }
        }
        return s;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    string str("1234");
    s.reverse(str, 0, 3);
    cout << str << endl;
    return 0;
}