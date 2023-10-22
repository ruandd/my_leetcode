//N 叉树的层序遍历
//ruan zheng
//2023-06-29 10:22:50

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

// Definition for a Node.
//class Node {
//public:
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//    int val;
//    vector<Node*> children;
//};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> line;
            for(int i = 0; i < size; i++) {
                Node* p = que.front();
                line.push_back(p->val);
                que.pop();
                for(int j = 0; j < p->children.size(); j++)
                    que.push(p->children[j]);
            }
            result.push_back(line);
        }
        return result;    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    Node* p1 = new Node(5);
    Node* p2 = new Node(6);
    vector<Node*> v1{p1, p2};
    Node* p3 = new Node(3, v1);
    Node* p4 = new Node(2);
    Node* p5 = new Node(4);
    vector<Node*> v2{p3, p4, p5};
    Node* root = new Node(1, v2);
    s.levelOrder(root);

    return 0;
}