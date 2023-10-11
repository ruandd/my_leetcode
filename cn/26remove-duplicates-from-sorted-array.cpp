//删除有序数组中的重复项
//ruan zheng
//2023-05-30 20:49:03

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*慢指针用来指向新数组的末尾元素，快指针寻找新元素*/
    int removeDuplicates(vector<int>& nums) {
//        int size = nums.size();
//        if(size < 2) return size;
//        int slow = 1, fast = 1;
//        for(; fast < size; fast++) {
//            if(nums[fast] != nums[fast-1])
//                nums[slow++] = nums[fast];
//        }
//        return slow;
        int slow = 0, fast = 0;
        for(; fast < nums.size(); fast++) {
            if(nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> ivec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ret = s.removeDuplicates(ivec);
    cout << ret << endl;
    return 0;
}