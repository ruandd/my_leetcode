//删除排序链表中的重复元素
//ruan zheng
//2023-10-16 09:48:07

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != nullptr ) {
            if(pre->val != cur->val) {
                pre = pre->next;
                cur = cur->next;
            }
            else {
                ListNode* tmp;
                /*虽然cur为空也会跳出循环，但是操作空指针会报错，必选先判断cur != nullptr*/
                while(cur != nullptr && pre->val == cur->val) {
                    tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
                pre->next = cur;
            }
        }
        return head;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    vector<int> vec{1, 1, 2, 3, 3};
    for(int i = 0; i < vec.size(); i++) {
        ListNode* cur = new ListNode(vec[i], nullptr);
        tail->next = cur;
        tail = cur;
    }
    s.deleteDuplicates(dummy->next);
    return 0;
};