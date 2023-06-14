//四数相加 II
//ruan zheng
//2023-06-14 13:59:47

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> map12, map34;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                //遍历nums1和nums2，处理第一个map
                int sum = nums1[i] + nums2[j];
                auto iter = map12.find(sum);
                //如果没有该元素，则插入
                if(iter == map12.end()) map12.insert({sum, 1});
                //如果已经有该“和”的情况，则对应的值加1
                else (iter->second)++;

                //遍历nums3和nums4，处理第二个map
                sum = nums3[i] + nums4[j];
                iter = map34.find(sum);
                if(iter == map34.end()) map34.insert({sum, 1});
                else (iter->second)++;
            }

        //开始遍历两个map;
        int num = 0;
        for(auto iter1=map12.cbegin(); iter1!=map12.cend(); iter1++) {
            auto iter2 = map34.find(-(iter1->first));
            if(iter2 != map34.end())
                num = num + (iter1->second) * (iter2->second);
        }
        return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}