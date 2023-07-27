//分发饼干
//ruan zheng
//2023-07-27 19:38:19

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 我的思路双重循环其实搞复杂了;
 * 因为实际上一个顺序对应的关系;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        for(int i = 0; i < g.size(); i++) {
            int j;
            for(j = 0; j < s.size(); j++) {
                if(s[j] >= g[i]) {
                    //饼干分配过了，置为0;
                    s[j] = 0;
                    num++;
                    break;
                }
            }
            if(j == s.size()) return num; //若内层循环结束j = s.size(),则此时没有满足条件的饼干，直接返回即可;
        }
        return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution so;
    vector<int> g{1, 2};
    vector<int> s{1, 2, 3};
    auto ret = so.findContentChildren(g, s);
    return 0;
}