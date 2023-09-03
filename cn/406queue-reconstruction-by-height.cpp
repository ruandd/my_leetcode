//根据身高重建队列
//ruan zheng
//2023-09-03 10:44:17

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        //第一维从大到小，第二维从小到大;
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] > v2[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;
        for(int i = 0; i < people.size(); i++) {
            result.insert(result.begin()+people[i][1], people[i]);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> ivec{{1, 3}, {4, 5}, {9, 3}, {4, 2}};
    s.reconstructQueue(ivec);
    return 0;
}