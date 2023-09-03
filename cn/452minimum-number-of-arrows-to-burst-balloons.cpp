//用最少数量的箭引爆气球
//ruan zheng
//2023-09-03 11:27:24

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        //第一维从小到大，第二维从小到大;
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int beg = points[0][0];
        int end = points[0][1];
        int sum = 0;
        for(int i = 1; i < points.size(); i++) {
            if(end >= points[i][0]) {
                beg = points[i][0];
                end = min(end, points[i][1]);      //必须取两者较小值，防止[4, 10] [6, 7]这种情况;
            }
            else {
                beg = points[i][0];
                end = points[i][1];
                sum++;
            }
        }
        return sum+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<vector<int>> vec{{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    s.findMinArrowShots(vec);
    return 0;
}