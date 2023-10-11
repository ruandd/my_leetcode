//在排序数组中查找元素的第一个和最后一个位置
//ruan zheng
//2023-03-02 17:39:57

#include <iostream>
#include <vector>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*寻找第一个等于target的数的位置*/
    int searchLeftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, leftBorder = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] == target) {
                leftBorder = mid;
                right = mid - 1;
            }
        }
        return leftBorder;
    }

    /*寻找最后一个等于target数的位置*/
    int searchRightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, rightBorder = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] == target) {
                rightBorder = mid;
                left = mid + 1;
            }
        }
        return rightBorder;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = searchLeftBorder(nums, target);
        int rightBorder = searchRightBorder(nums, target);
        return {leftBorder, rightBorder};

    }
};
//leetcode submit region end(Prohibit modification and deletion)





int main(){
    class Solution s;
    vector<int> ivec{5, 7, 7, 8, 8, 10};
    auto re = s.searchRange(ivec, 8);
    cout << re[0] << "  " << re[1] << endl;
    return 0;
}