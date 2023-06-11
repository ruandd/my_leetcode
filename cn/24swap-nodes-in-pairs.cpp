//两两交换链表中的节点
//ruan zheng
//2023-06-08 14:22:47

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

/*
 * 这道题采用双指针就可以解决;
 * 关键问题是最好采用虚头节点,这样方便删除节点;
 * 还有就是删除第一个节点与后面的不统一,需要做单独处理;
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        //添加虚拟头节点,统一操作
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        //指针每次迭代需要移动两步，所以迭代条件需要注意;
        //同时这种操作避免了对单节点特殊情况的判断;
        while(curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp1 = curr->next;
            ListNode* tmp2 = curr->next->next->next;
            //开始交换
            //交换操作的时候注意:curr未被赋值前指针不发生变动!!!!!!;
            curr->next = curr->next->next;
            curr->next->next = tmp1;
            tmp1->next->next->next = tmp2;

            //注意是移动两位;
            curr = curr->next->next;
        }
        return dummyHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i=2; i<5; i++) {
        ListNode* tmp = new ListNode(i);
        p->next = tmp;
        p = p->next;
    }
    auto ret = s.swapPairs(head);
    return 0;
}