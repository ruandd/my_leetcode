//在排序数组中查找元素的第一个和最后一个位置
//ruan zheng
//2023-03-02 17:39:57

#include <iostream>
#include <vector>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = searchLeftBorder(nums, target);
        int rightBorder = searchRightBorder(nums, target);
        cout << leftBorder << rightBorder << endl;
        if(leftBorder == -2 || rightBorder == -2) return vector<int> {-1, -1};
        if(rightBorder - leftBorder > 1) return {leftBorder+1, rightBorder-1};
        return {-1, -1};
    }

    int searchRightBorder(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        int rightBorder = -2;   //记录右边界;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target)
                right = mid - 1;
            else{
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    int searchLeftBorder(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        int leftBorder = -2;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target)
                left = mid + 1;
            else{
                right = mid - 1;
                leftBorder = right;
            }
        }
        return leftBorder;
    }

};
//leetcode submit region end(Prohibit modification and deletion)





int main(){
    class Solution s;
    vector<int> ivec{1, 2, 3, 3, 5};
    auto re = s.searchRange(ivec, 3);
    return 0;
}