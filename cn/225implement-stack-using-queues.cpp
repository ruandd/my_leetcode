//用队列实现栈
//ruan zheng
//2023-06-21 17:16:25

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        while(que.size() != 1) {
            auto tmp = que.front();
            que.pop();
            bakeup_que.push(tmp);
        }
        auto ret = que.front();
        que.pop();

        while(!bakeup_que.empty()) {
            auto tmp = bakeup_que.front();
            bakeup_que.pop();
            que.push(tmp);
        }

        return  ret;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que, bakeup_que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}