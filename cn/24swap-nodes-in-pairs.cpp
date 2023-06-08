//两两交换链表中的节点
//ruan zheng
//2023-06-08 14:22:47

#include<string>
#include<vector>
#include<iostream>

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
        if(!head || !head->next) return head;
        ListNode* pre = head;
        ListNode* curr = head->next;
        ListNode* newHead = curr;
        while(pre && curr) {
            pre->next = curr->next;
            curr->next = pre;
            pre = pre->next;
            curr = pre->next;
        }
        return newHead;
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