//环形链表 II
//ruan zheng
//2023-06-09 21:20:52

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
 * 这道题关键是分析过程，需要用到一定的数学知识;
 * 第二个关键点是while循环的判断条件;
 * 快指针一次走两部有可能直接跳过末尾节点到未知内存，这是关键;
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode* p = head;
                ListNode* q = fast;
                for(int i=0; p!=q; i++) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}