//无重叠区间
//ruan zheng
//2023-09-04 09:32:00

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int pos = intervals[0][1];                   //起始位置的end;
        int count = 1;                               //计数符和条件的区间;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= pos) {
                count++;
                pos = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> vec{{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95},
                            {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
    s.eraseOverlapIntervals(vec);
    return 0;
}