//反转链表
//ruan zheng
//2023-06-07 22:18:42

#include<string>
#include<vector>
#include<iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

//    ListNode* recursion(ListNode* p, ListNode* q){
//        if(!q) return p;
//        ListNode* tail = q;
//        while(tail->next != nullptr)
//            tail = tail->next;
//        tail->next = p;
//        p->next = nullptr;
//        recursion(q,q->next);
//    }

    ListNode* reverseList(ListNode* head) {
#if 0
        stack<ListNode*> st;
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        //先把元素逐个入栈
        while(head != nullptr) {
            st.push(head);
            head = head->next;
        }
        //因为没有采用虚头节点，所以得先出栈一个，使下面的操作一致;
        if(!st.empty()) {
            newHead = st.top();
            tail = newHead;
            st.pop();
        }
        while(!st.empty()) {
            tail->next = st.top();
            st.pop();
            tail = tail->next;
        }
        //给最后一个元素的next指针赋nullptr
        if(tail != nullptr) tail->next = nullptr;
        return newHead;
#endif

#if 0
        if(head == nullptr) return head;
        auto ret = recursion(head, head->next);
        return ret;
#endif

#if 1   //双指针迭代法
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* curr = head->next;
        head->next = nullptr;
        while(curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
#endif
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    ListNode* head = new ListNode(1, nullptr);
    ListNode* tail = head;
    for(int i=2; i<6; ++i) {
        ListNode* tmp = new ListNode(i, nullptr);
        tail->next = tmp;
        tail = tail->next;
    }
    head = nullptr;
    auto ret = s.reverseList(head);
    while(ret) {
        cout << ret->val<< endl;
        ret = ret->next;
    }
    return 0;
}