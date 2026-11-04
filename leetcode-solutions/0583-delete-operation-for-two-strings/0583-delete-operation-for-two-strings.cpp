class Solution {
public:
    int minDistance(string word1, string word2) {
        int a=word1.size();
        int b=word2.size();
        vector<vector<int>>dp(a,vector<int>(b));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(word1[i]==word2[j]){
                    dp[i][j]=1;
                }
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (word1[i] == word2[j] && i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return a+b-2*dp[a-1][b-1];
    }
};