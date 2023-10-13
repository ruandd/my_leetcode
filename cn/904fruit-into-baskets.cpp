//水果成篮
//ruan zheng
//2023-10-12 10:41:02

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * 本题目关键是当超过两个种类的水果时，如何删除最前方的水果，采用map可以方便处理;
 * 第二个就是先要处理right越界的情况，再去计算子序列长度
 * */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int result = INT32_MIN;
        int left = 0;
        for(int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;
            while(cnt.size() > 2) {
                cnt[fruits[left]]--;
                if(cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            /*必须放在处理cnt.size() > 2之后*/
            result = max(result, right - left + 1);
        }
        return (result == INT32_MIN) ? 0 : result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    s.totalFruit(vec);
    return 0;
}