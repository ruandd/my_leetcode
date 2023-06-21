//用栈实现队列
//ruan zheng
//2023-06-21 16:10:11

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        inSt.push(x);
    }

    
    int pop() {
        if(outSt.empty()) {
            while(!inSt.empty()) {
                auto tmp = inSt.top();
                outSt.push(tmp);
                inSt.pop();
            }
        }
        if(!outSt.empty()) {
            auto ret = outSt.top();
            outSt.pop();
            return ret;
        }
        return NULL;

    }
    
    int peek() {
        auto ret = pop();
        outSt.push(ret);
        return ret;
    }
    
    bool empty() {
        return inSt.empty() && outSt.empty();
    }
private:
    stack<int> inSt, outSt;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}