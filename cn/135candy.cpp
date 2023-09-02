//分发糖果
//ruan zheng
//2023-09-02 20:18:58

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 0);
        candy[0] = 1;
        //从左向右遍历;
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
            else
                candy[i] = 1;
        }
        //从右往左遍历;
        for(int j = ratings.size()-2; j >= 0; j--) {
            if(ratings[j] > ratings[j+1])
                candy[j] = max(candy[j], candy[j+1] + 1);
        }
        int result = 0;
        for(int i : candy) result += i;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}