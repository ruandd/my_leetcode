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
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        return slow;
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