//滑动窗口最大值
//ruan zheng
//2023-06-23 20:26:29

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    class myQueue {
    public:
        void push(int value) {
            /*为空则直接插入元素，否则删除前面较小的元素，再插入*/
            if(que.empty()) {
                que.push_back(value);
                return;
            }
            while(!que.empty() && (value > que.back())) {
                que.pop_back();
            }
            que.push_back(value);

        }

        void pop(int value) {
            if(value == que.front())
                que.pop_front();
        }

        int front() {
            return que.front();
        }
    private:
        deque<int> que;
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQueue que;
        vector<int> result;
        /*初始化*/
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        for(int i = 0; i < nums.size() - k; i++) {
            result.push_back(que.front());
            que.pop(nums[i]);
            que.push(nums[i+k]);
        }
        result.push_back(que.front());
        return result;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> ivec{1, 3, -1, -3, 5, 3, 6, 7};
    auto ret = s.maxSlidingWindow(ivec, 3);
    return 0;
}