/* math property */
class Solution {
public:
    int integerBreak(int n) {
        int d = n/3;
        int r = n%3;
        if(n==2) return 1;if(n==3) return 2;
        if(r==0) return pow(3,d);
        if(r==1) return pow(3,d-1)*4;
        if(r==2) return pow(3,d)*2;
    }
};
/* DP solution
explaination:
// dp[i] record currently the max value for number i
// j*(i-j) is the new value calculated by j*(i-j)
// dp[j]*dp[i-j]: two supposed max value recorded in dp[]
// dp[j]*(i-j): in case that dp[i-j] is still 1
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 0) return 0; 
        vector<int> dp(n+1,1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i],max(j*(i-j),dp[j]*max(dp[i-j],(i-j))));
                
            }
        }
        return dp[n];
    }
};

