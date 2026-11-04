class Solution {
public:
    int minInsertions(string s) {
        int a=s.size();
        vector<vector<int>>dp(a,vector<int>(a,0));
        string text1=s;
        reverse(s.begin(),s.end());
        string text2=s;
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
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
        return s.size()-dp[a-1][a-1];
    }
};