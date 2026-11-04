class Solution {
public:
    bool comp(string &a,string &b){
        if(a.size()!=b.size()+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<a.size()){
            if(j<b.size() && a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }
        return false;
    }
    static bool compa(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compa);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(comp(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};