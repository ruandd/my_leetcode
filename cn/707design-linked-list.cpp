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
    //定义链表节点结构体;
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) { }
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if(index >= _size) return -1;
        LinkedNode* p = _dummyHead;    //p为链表第一个节点;
        for(int i=0; i<=index; i++) {
            p = p->next;
        }
        return p->val;

    }

    void addAtHead(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = _dummyHead->next;
        _dummyHead->next = tmp;
        ++_size;
    }

    void addAtTail(int val) {
        LinkedNode* tmp = new LinkedNode(val);
        LinkedNode* p = _dummyHead;
        while(p->next != nullptr)
            p = p->next;
        p->next = tmp;
        ++_size;
    }

    /*
     * 对于插入元素来说，相对来说比较浮躁;
     * 因为插入的时候链表可能为空，所以一定要注意操作的统一;
     * 必须对虚指针头节点操作，否则会出大问题;
     */
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        else if(index == _size) addAtTail(val);
        else {
            LinkedNode* p = _dummyHead;
            for(int i=0; i<index; i++) {
                p = p->next;
            }
            LinkedNode* tmp = new LinkedNode(val);
            tmp->next = p->next;
            p->next = tmp;
            ++_size;
        }
    }

    void deleteAtIndex(int index) {
        if(index < _size) {
             LinkedNode* p = _dummyHead;
             for(int i=0; i<index; i++)
                 p = p->next;
             p->next = p->next->next;
             --_size;
        }
    }

    int _size;
    LinkedNode* _dummyHead;
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
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtIndex(0, 10);
    myLinkedList.addAtIndex(0, 20);
    myLinkedList.addAtIndex(1, 30);
    auto ret = myLinkedList.get(1);
    cout << ret << endl;
    for(auto p = myLinkedList._dummyHead; p!= nullptr; p=p->next)
        cout << p->val << endl;
    myLinkedList.deleteAtIndex(1);
    for(auto p = myLinkedList._dummyHead; p!= nullptr; p=p->next)
        cout << p->val << endl;

    return 0;
}