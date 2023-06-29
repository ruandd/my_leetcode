//N 叉树的层序遍历
//ruan zheng
//2023-06-29 10:22:50

#include <string>
#include <vector>
#include <iostream>
#include <queue>

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
        queue<Node*> que;
        //储存结果;
        vector<vector<int>> result;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            //保存每一层的值;
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                auto p = que.front();
                que.pop();
                vec.push_back(p->val);
                for(int j = 0; j < p->children.size(); j++)
                    que.push(p->children[j]);
            }
            result.push_back(vec);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}