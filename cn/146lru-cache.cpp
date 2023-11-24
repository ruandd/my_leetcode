//LRU 缓存
//ruan zheng
//2023-11-24 10:25:07

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
private:
    struct LinkNode {
        int key, value;
        LinkNode* pre;
        LinkNode* next;
        LinkNode():key(0), value(0), pre(nullptr), next(nullptr) { }
        LinkNode(int key, int value): key(key), value(value), pre(nullptr), next(nullptr) { }
    };
    LinkNode* dummyHead;
    LinkNode* dummyTail;
    unordered_map<int, LinkNode*> hash;
    int capacity;
    int size;
public:
    /*初始化头节点，里面记录当前元素数量*/
    LRUCache(int capacity): capacity(capacity){
        size = 0;
        dummyHead = new LinkNode();
        dummyTail = new LinkNode();
        dummyHead->next = dummyTail;
        dummyTail->pre = dummyHead;
    }

    int get(int key) {
        auto ans = hash.find(key);
        if(ans == hash.end()) return - 1;
        /*存在元素，更新元素到链表尾部*/
        auto changeNode = ans->second;
        changeNode->pre->next = changeNode->next;
        changeNode->next->pre = changeNode->pre;
        /*插入到链表尾部*/
        auto preNode = dummyTail->pre;
        preNode->next = changeNode;
        dummyTail->pre = changeNode;
        changeNode->pre = preNode;
        changeNode->next = dummyTail;

        return ans->second->value;
    }

    void put(int key, int value) {
        auto ans = hash.find(key);
        /*关键字已经存在，则更新hash和链表节点位置*/
        if(ans != hash.end()) {
            /*从链表中取出*/
            auto changeNode = ans->second;
            changeNode->pre->next = changeNode->next;
            changeNode->next->pre = changeNode->pre;
            /*插入到链表尾部*/
            auto preNode = dummyTail->pre;
            preNode->next = changeNode;
            dummyTail->pre = changeNode;
            changeNode->pre = preNode;
            changeNode->next = dummyTail;

            changeNode->value = value;
        }
        /*关键字不存在，插入新元素；更新链表和hash以及size*/
        else {
            LinkNode* newNode = new LinkNode(key, value);
            /*更新hash和size*/
            hash[key] = newNode;
            size++;
            /*更新链表,在尾部插入元素*/
            auto preNode = dummyTail->pre;
            preNode->next = newNode;
            dummyTail->pre = newNode;
            newNode->pre = preNode;
            newNode->next = dummyTail;
            /*超出cache容量，则删除队列头部元素*/
            if(size > capacity) {
                auto deletedTmp = dummyHead->next;
                auto deletedKey = deletedTmp->key;
                dummyHead->next = dummyHead->next->next;
                dummyHead->next->next->pre = dummyHead;
                hash.erase(deletedKey);
//                delete deletedTmp;
                size--;
            }

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    LRUCache* lru = new LRUCache(1);
    lru->put(2, 1);
    lru->get(2);
    lru->put(3,2);
    lru->get(2);
    lru->get(3);

    return 0;
}