//删除链表的倒数第 N 个结点
//ruan zheng
//2023-06-08 16:26:53

#include<string>
#include<vector>
#include<iostream>

using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0, head);
        ListNode* left = dummyhead;
        ListNode* right = head;
        while(n--) {
            right = right->next;
        }
        while(right != nullptr) {
            left = left->next;
            right = right->next;
        }
        if(left->next == head) return head->next;
        left->next = left->next->next;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}