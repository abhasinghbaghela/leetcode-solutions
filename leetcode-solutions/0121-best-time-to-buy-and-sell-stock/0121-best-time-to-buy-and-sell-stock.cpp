class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int mp=0;
        for(int i=1;i<n;i++){
            int sell=prices[i];
            int profit=sell-buy;
            mp=max(mp,profit);
            buy=min(buy,sell);
        }
        return mp;
    }
};