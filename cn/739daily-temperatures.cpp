//每日温度
//ruan zheng
//2023-10-21 20:43:10

#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> que;
        vector<int> result(temperatures.size(), 0);
        /*保持栈内元素单调递减*/
        for(int i = 0; i < temperatures.size(); i++) {
            if(que.empty()) {
                que.push_back(i);
                continue;
            }
            else if(temperatures[i] > temperatures[que.back()]) {
                /*注意判断非空*/
                while(!que.empty() && temperatures[i] > temperatures[que.back()]) {
                    result[que.back()] = i - que.back();
                    que.pop_back();
                }
                que.push_back(i);
            }
            else {
                que.push_back(i);
            }

        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(v);
    return 0;
}