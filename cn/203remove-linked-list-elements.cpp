//移除链表元素
//ruan zheng
//2023-06-04 22:05:56

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

 /*
  * 对于单向链表的操作如果有虚拟头节点的话，就可以统一操作，这道题给的节点是不带虚拟头节点的;
  * 所以对于头节点和后续节点的操作是不一致的;
  * 如果链表头节点就有val，则head = head->next，并delete tmp，回收内存
  * 循环结束之链表如果为空则返回
  * 不返回的话，链表至少有一个元素且该元素不可能为val
  * 接下来按序处理即可
  */

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;              //指向下一个节点，并释放内存;
            delete tmp;                     //顺序不可以反;
        }
        if(head == nullptr) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != nullptr) {
            if(q->val == val) {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else {
                q = q->next;
                p = p->next;
            }
        }
        return head;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    ListNode* head = new ListNode(1, nullptr);
    ListNode* p = head;
    int size = 6;
    int nums[] = {2, 6, 3, 4, 5, 6};
    for(int i=0; i<size; i++){
        ListNode* tmp = new ListNode(nums[i], nullptr);
        p->next = tmp;
        p = p->next;
    }
    head = s.removeElements(head, 6);
    while(head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}