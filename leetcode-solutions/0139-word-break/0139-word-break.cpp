class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(auto &w:wordDict){
                int st=i-w.length();
                if(st>=0 && dp[st] && s.substr(st,w.length())==w){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};