//二分查找
//ruan zheng
//2023-03-02 16:45:42

#include <iostream>
#include<string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid;
            else
                return mid;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    class Solution s;
    vector<int> ivec{1, 2, 3, 4, 5};
    int tg = 3;
    auto result = s.search(ivec, tg);
    cout << result << endl;
    return 0;
}
