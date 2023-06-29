//填充每个节点的下一个右侧节点指针
//ruan zheng
//2023-06-29 10:53:09

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            //因为是一边出队，一边入队，所以必须用size找到界限;
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto pre = que.front();
                que.pop();
                //i == size - 1，说明已经取完，next置为nullptr;
                auto p = (i == size - 1) ? nullptr : que.front();
                pre->next = p;
                if(pre->left) que.push(pre->left);
                if(pre->right) que.push(pre->right);
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}