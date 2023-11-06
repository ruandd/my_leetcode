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
        /*st中的元素是单调递减的*/
        vector<int> st;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            if(i == 0) st.push_back(i);
            else if(temperatures[i] < temperatures[st.back()]) st.push_back(i);
            else {
                while(!st.empty() && temperatures[st.back()] < temperatures[i]) {
                    int index = st.back();
                    st.pop_back();
                    result[index] = i - index;
                }
                st.push_back(i);
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