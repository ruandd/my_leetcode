//合并两个有序数组
//ruan zheng
//2023-10-19 12:45:39

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        if(n == 0) return;
        vector<int> tmp(nums1.begin(), nums1.begin() + m);
        /*i和j指向待合并的两个数组，k指向合并后的数组*/
        int i = 0, j = 0, k = 0;
        while( i < m && j < n) {
            if(tmp[i] <= nums2[j]) {
                nums1[k++] = tmp[i];
                i++;
            }
            else {
                nums1[k++] = nums2[j];
                j++;
            }
        }
        while(i == m && j < n) nums1[k++] = nums2[j++];
        while(j == n && i < m) nums1[k++] = tmp[i++];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums1{1};
    vector<int> nums2;
    s.merge(nums1, 1, nums2, 0);

    return 0;
}