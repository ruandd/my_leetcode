//动态口令
//ruan zheng
//2023-10-18 10:30:32

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    string reverseLeftWords(string s, int n) {
//        for(int k = 0; k < n; k++) {
//            auto tmp = s[0];
//            for(int i = 0; i < s.size()-1; i++) {
//                s[i] = s[i+1];
//            }
//            s[s.size()-1] = tmp;
//        }
//        return s;
//    }

    void reverse(string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }
    string dynamicPassword(string password, int target) {
        /*必须有这一步*/
        int n = password.size() - target;
        reverse(password, 0, password.size() - 1);
        reverse(password, 0, n - 1);
        reverse(password, n, password.size() - 1);
        return password;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}