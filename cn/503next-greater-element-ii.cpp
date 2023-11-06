//下一个更大元素 II
//ruan zheng
//2023-11-04 22:21:19

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        /*st栈中只保存序号*/
        stack<int> st;
        for(int i = 0; i < nums.size() * 2 - 1; i++) {
            while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
                auto tmp = st.top();
                st.pop();
                result[tmp] = nums[i % nums.size()];
            }
            st.push(i % nums.size());
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{1, 2, 1};
    auto ret = s.nextGreaterElements(vec);
    return 0;
}