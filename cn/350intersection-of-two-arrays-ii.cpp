//两个数组的交集 II
//ruan zheng
//2023-06-11 11:33:50

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //需要把记录数组初始化为0;在这里不可以使用static会有问题;
        //使用 int recode[1001] = {0];
        int record1[1001] = {0}, record2[1001] = {0};
        for(auto i: nums1) {
            record1[i] += 1;
        }
        for(auto i: nums2) {
            record2[i] += 1;
        }
        vector<int> resu;
        for(int index=0; index<1001; index++) {
            int nums = (record1[index] < record2[index]) ? record1[index]: record2[index];
            while(nums--) resu.push_back(index);
        }
        return  resu;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}