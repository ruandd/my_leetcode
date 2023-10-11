//有效的完全平方数
//ruan zheng
//2023-10-11 14:52:35

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        /*关键在于计算mid需要保留整数，而计算是否相等需要小数*/
        int left = 1, right = num;
        int mid;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(mid < static_cast<double>(num)/mid)
                left = mid + 1;
            else if(mid > static_cast<double>(num)/mid)
                right = mid - 1;
            else if(mid == static_cast<double>(num)/mid)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}