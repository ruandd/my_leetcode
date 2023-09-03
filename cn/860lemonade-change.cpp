//柠檬水找零
//ruan zheng
//2023-09-03 10:03:45

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int haveBill[3] = {0, 0, 0};
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                haveBill[0] += 1;           //5元直接收入;
                continue;
            }
            if(bills[i] == 10 && haveBill[0] > 0) {
                haveBill[0] -= 1;           //10元需要有5元找零;
                haveBill[1] += 1;
                continue;
            }
            if(bills[i] == 20) {
                //优先用10元和5元找零;
                if(haveBill[0] > 0 && haveBill[1]  > 0) {
                    haveBill[0] -= 1;
                    haveBill[1] -= 1;
                    haveBill[2] += 1;
                    continue;
                }
                if(haveBill[0] >= 3) {
                    haveBill[0] -= 3;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}