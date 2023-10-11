//有序数组的平方
//ruan zheng
//2023-06-02 21:51:53

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ivec;
        int t1, t2;
        while(left <= right) {
            t1 = nums[left]*nums[left];
            t2 = nums[right]*nums[right];
            if(t1 < t2){
                ivec.push_back(t2);
                --right;
            }
            else{
                ivec.push_back(t1);
                ++left;
            }
        }
        reverse(ivec.begin(), ivec.end());
        return ivec;

        /*二刷*/
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;
        while(left <= right) {
            if(pow(nums[left], 2) > pow(nums[right], 2))
                result[index--] = pow(nums[left++], 2);
            else
                result[index--] = pow(nums[right--], 2);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> v{-4, -1, 0, 3, 10};
    auto ret = s.sortedSquares(v);
    for(auto i: ret)
        cout << i << " ";
    return 0;
}