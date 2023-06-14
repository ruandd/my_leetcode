//快乐数
//ruan zheng
//2023-06-14 11:15:08

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> split_num(int num) {
        vector<int> result;
        while(num) {
            int remainder = (num%10);
            result.push_back(remainder);
            num = (num/10);
        }
        return result;
    }

    bool isHappy(int n) {
        std::unordered_set<int> result_set;  //存放结果,避免循环;
        vector<int> tmp_vec;
        do {
            result_set.insert(n);       //记录在set中
            auto tmp_vec = split_num(n);
            int sum = 0;                     //计算累计和;
            for(auto bg=tmp_vec.begin(); bg!=tmp_vec.end(); bg++) {
                sum += (*bg)*(*bg);
            };
            n = sum;
        } while(n != 1 && result_set.find(n) == result_set.end());
        if(n == 1) return true;
        else return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.isHappy(19);
    cout << "hello";
    return 0;
}