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
        int left = 1, right = x ;
        //左闭右开不行，如果x=1则失败
        //还得是闭区间
        //不要用乘法，容易溢出
        //把乘法转换为除法
        while( left <= right ){
            int mid = left + (right - left)/2;
            if( mid <= (x/mid) && x/(mid + 1) < (mid + 1) )
                return mid;
            else if(mid > (x/mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto result = s.mySqrt(8);
    cout << result << endl;
    return 0;
}