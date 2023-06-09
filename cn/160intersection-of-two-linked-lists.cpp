//相交链表
//ruan zheng
//2023-06-09 20:12:05

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
 * 这道题需要注意审题，相等条件是两个指针指向同一个节点，而不是节点值相等;
 *
 */

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        while(p) {
            ++sizeA;
            p = p->next;
        }
        while(q) {
            ++sizeB;
            q = q->next;
        }
        p = headA, q = headB;
        //比较两个链表的长度，然后移动较长的链表和较短的链表对齐;
        //需要考虑到没有想等，退出循环的情况;
        if(sizeA > sizeB) {
            int diff = sizeA - sizeB;
            while(diff--) p = p->next;
            while(p && q) {
                if(p == q) return p;
                p = p->next;
                q = q->next;
            }
            return nullptr;
        }
        else {
            int diff = sizeB - sizeA;
            while(diff--) q = q->next;
            while(p && q) {
                if(p == q) return p;
                p = p->next;
                q = q->next;
            }
            return nullptr;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}