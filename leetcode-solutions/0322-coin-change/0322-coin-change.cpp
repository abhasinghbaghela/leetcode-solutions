class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX-1));
        for(int a=0;a<=n;a++){
            dp[a][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int a=0;a<=amount;a++){
                if(coins[i-1]<=a){
                    dp[i][a]=min(dp[i-1][a],1+dp[i][a-coins[i-1]]);
                }else{
                    dp[i][a]=dp[i-1][a];
                }
            }
        }
        if(dp[n][amount]==INT_MAX-1){
            return -1;
        }else{
            return dp[n][amount];
        }
    }
};