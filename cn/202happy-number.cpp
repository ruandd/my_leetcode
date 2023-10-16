//快乐数
//ruan zheng
//2023-06-14 11:15:08

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <cstdlib>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    vector<int> split_num(int num) {
//        vector<int> result;
//        while(num) {
//            int remainder = (num%10);
//            result.push_back(remainder);
//            num = (num/10);
//        }
//        return result;
//    }

    int squareSum(int n) {
        string s = to_string(n);
        int sum = 0;
        for(auto c: s) {
            sum += pow(c - '0', 2);
        }
        return sum;
    }

    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_set<int> s;
        s.insert(n);
        int sum = squareSum(n);
        while(s.find(sum) == s.end()) {
            if(sum == 1) return true;
            s.insert(sum);
            sum = squareSum(sum);
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.isHappy(2);
    cout << "hello";
    return 0;
}