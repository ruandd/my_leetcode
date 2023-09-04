//合并区间
//ruan zheng
//2023-09-04 13:13:57

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //start从小到大,如果start相同,end也从小到大排列;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;                //保存最终结果;
        vector<int> tmp(intervals[0]);             //记录每个合并后的数组;
        for(int i = 1; i < intervals.size(); i++) {
            if(tmp[1] >= intervals[i][0]) {
                //有重叠区域;必须用max取较大值;
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
            else {
                //无重叠区域;
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        result.push_back(tmp);
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}