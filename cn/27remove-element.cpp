//移除元素
//ruan zheng
//2023-03-09 21:25:17

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int tail = nums.size() - 1, search = tail;
        // for(;search >= 0; search--) {
        //     if(nums[search] == val) {
        //         nums[search] = nums[tail];
        //         tail--;
        //     }
        // }
        // return tail+1;
        int slow = 0, fast = 0;
        for(; fast < nums.size(); fast++) {
            if(nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums{3, 2, 2, 3};
    auto re = s.removeElement(nums, 3);
    cout <<  re << endl;
    for(auto i: nums)
        cout << i << " ";
    return 0;
}