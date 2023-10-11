//搜索插入位置
//ruan zheng
//2023-03-02 17:01:00

#include<string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //左右都是闭区间
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target > nums[mid])
                left = mid + 1;
            else if(target < nums[mid])
                right = mid - 1;
            else
                return mid;
        }
        return left;


//        int left = 0, right = nums.size();
//        while(left < right)  {
//            int mid = left + (right - left)/2;
//            if(nums[mid] < target)
//                left = mid + 1;
//            else if(nums[mid] > target)
//                right = mid;
//            else
//                return mid;
//        }
//        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}