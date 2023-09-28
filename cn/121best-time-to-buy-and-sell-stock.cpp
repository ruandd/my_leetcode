//买卖股票的最佳时机
//ruan zheng
//2023-09-21 10:22:56

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        //dp[i][0]持有股票所能获得的最多现金，dp[i][1]不持有股票能获得的最多现金;
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
            //不太理解;
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }
        return dp[len-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


long long f(long long d)
{
    long long i;
    long long num=0;
    for(i=1;i<sqrt(d);i++)
    {
        if(d%i==0){
            num=num+1;
            // cout<<"a"<<i<<endl;
        }
    }  //如果sqrt(d)不是整数，则约数个数为2*num，如果sqrt(d)是整数时，约数的个数为2*num+1
    num=2*num;

    long long s=sqrt(d);

    if(d==s*s) num++;
    return num;
}

int main(){
    int n;
    cin>>n;

    vector<int> q1,q2;

    for(int i = 1; i <= n; i ++ )
    {
        st[i] = false;
        int x;
        cin>>x;
        if(x & 1){st[i] = true;q1.push_back(x);}
        else q2.push_back(x);
    }

    sort(q1.begin(),q1.end());
    sort(q2.begin(),q2.end());

    vector<int> ans(n + 1);

    int a2 = 0,a1 = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(st[i])ans[i] = q1[ a1++ ];
        else ans[i] = q2[ a2++ ];
    }

    for(int i = 1; i < n ; i ++ )
        if(ans[i + 1] < ans[i]){cout<<"NO\n";return;}
}