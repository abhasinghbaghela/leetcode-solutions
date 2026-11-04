class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a=text1.size();
        int b=text2.size();
        vector<vector<int>>dp(a,vector<int>(b));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1;
                }
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (text1[i] == text2[j] && i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return dp[a-1][b-1];
    }
};