//设计链表
//ruan zheng
//2023-06-07 15:25:37

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode():val(0), next(nullptr) {};
        ListNode(int val):val(val), next(nullptr) {};
    };

    ListNode* head = nullptr;
    int length = 0;


    MyLinkedList() {
        head = new ListNode();
        head->next = nullptr;
    }

    int get(int index) {
        if(index >= length) return -1;
        ListNode* cur = head;
        while(index-- >= 0)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = head->next;
        head->next = tmp;
        length++;
    }

    void addAtTail(int val) {
        addAtIndex(length, val);
    }

    void addAtIndex(int index, int val) {
        ListNode* tmp = new ListNode(val);
        if(index > length) return;
        ListNode* cur = head;
        while(index-- > 0) {
            cur = cur->next;
        }
        tmp->next = cur->next;
        cur->next = tmp;
        length++;
    }

    void deleteAtIndex(int index) {
        if(index >= length) return;
        ListNode* cur = head;
        while(index-- > 0) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        length--;
    }

    void print() {
        ListNode* cur = head->next;
        while(cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    auto ret1 = myLinkedList.get(1);
    myLinkedList.deleteAtIndex(1);
    auto ret2 = myLinkedList.get(1);
    myLinkedList.print();


    return 0;
}