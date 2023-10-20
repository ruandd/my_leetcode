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
    stack<int> in_st;
    stack<int> out_st;
    MyQueue() {

    }

    void push(int x) {
        /*初始时都为空*/
        if(in_st.empty() && out_st.empty()) {
            in_st.push(x);
            return;
        }
        /*上一步操作是入栈*/
        if(!in_st.empty() && out_st.empty())
            in_st.push(x);
        /*上一步操作时出栈*/
        if(in_st.empty() && !out_st.empty()) {
            /*把out_st的元素都放到in_out中*/
            while(!out_st.empty()) {
                auto tmp = out_st.top();
                out_st.pop();
                in_st.push(tmp);
            }
            /*元素入栈*/
            in_st.push(x);
        }
    }

    int pop() {
        /*上一步操作是出栈*/
        if(in_st.empty() && !out_st.empty()) {
            auto tmp = out_st.top();
            out_st.pop();
            return tmp;
        }
        /*上一步操作是入栈*/
        if(!in_st.empty() && out_st.empty()) {
            /*把in_st的元素放到out_st中*/
            while(!in_st.empty()) {
                auto tmp = in_st.top();
                in_st.pop();
                out_st.push(tmp);
            }
            auto tmp = out_st.top();
            out_st.pop();
            return tmp;
        }
        return 1;
    }

    int peek() {
        /*如果元素都在in_st中，则需要转移到out_st中*/
        if(!in_st.empty() && out_st.empty()) {
            /*把in_st的元素放到out_st中*/
            while(!in_st.empty()) {
                auto tmp = in_st.top();
                in_st.pop();
                out_st.push(tmp);
            }
            return out_st.top();
        }
        return out_st.top();
    }

    bool empty() {
        return in_st.empty() && out_st.empty();
    }
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
    MyQueue queue;
    queue.push(1);
    queue.pop();
    cout << queue.empty() << endl;
    return 0;
}