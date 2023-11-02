//所有可能的路径
//ruan zheng
//2023-11-02 12:47:02

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int n) {
        /*到达终点*/
        if(n == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        /*遇到死路*/
        if( n < graph.size() - 1 && graph[n].empty()) return;

        for(int i = 0; i < graph[n].size(); i++) {
            int next = graph[n][i];
            path.push_back(next);
            dfs(graph, next);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}