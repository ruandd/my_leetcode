//加油站
//ruan zheng
//2023-09-02 16:43:29

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 如果totalSum < 0,则不可以跑完一圈;
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currSum = 0;
        int totalSum = 0;
        for(int i = 0; i < gas.size(); i++) {
            currSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(currSum < 0) {
                currSum = 0;
                start = i + 1;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    auto ret = s.canCompleteCircuit(gas, cost);
    return 0;
}