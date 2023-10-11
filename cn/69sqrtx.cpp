//x 的平方根 
//ruan zheng
//2023-03-09 20:56:57

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        /*不能除0，故特殊处理*/
        if(x <= 1) return x;
        int left = 0, right = x;
        int mid;
        while(left <= right) {
            mid = left + (right - left)/2;
            if( mid <= x/mid && (mid+1) > x/(mid+1))
                return mid;
            else if((mid+1) <= x/(mid+1))
                left = mid + 1;
            else if( mid > x/mid)
                right = mid - 1;
        }
        return mid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto result = s.mySqrt(8);
    cout << result << endl;
    return 0;
}