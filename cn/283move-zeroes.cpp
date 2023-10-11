//移动零
//ruan zheng
//2023-05-30 21:18:38

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/*
 * 这道题是移动0，把0的位置全部换到数组的末尾，就不可以采用复制的方法，因为这样会
 * 改变0的个数；官方题解的思路很好，就是把left作为已经处理好的元素末尾，而right
 * 去寻找非0元素
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//        int left = 0, right = 0;
//        int n = nums.size();
//        while(right < n) {
//            if(nums[right]) {
//                swap(nums[left], nums[right]);
//                ++left;
//            }
//            ++right;
//        }

    /*二刷*/
        int slow = 0, fast = 0;
        for(; fast < nums.size(); fast++){
            if(nums[fast] != 0) {
                swap(nums[slow++], nums[fast]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}