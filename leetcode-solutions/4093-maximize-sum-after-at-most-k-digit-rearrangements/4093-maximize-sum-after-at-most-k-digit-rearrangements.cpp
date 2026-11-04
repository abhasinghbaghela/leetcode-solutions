class Solution {
public:
    int bignum(int n){
        int t=n;
        vector<int>nums;
        while(t){
            nums.push_back(t%10);
            t=t/10;
        }
        sort(nums.begin(),nums.end());
        int k=0;
        for(int i=nums.size()-1;i>=0;i--){
            k*=10;
            k+=nums[i];
        }
        return k;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int>temp=nums;
        vector<pair<int,int>>mpp;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int big=bignum(temp[i]);
            mpp.push_back({big-temp[i],big});
            ans+=temp[i];
        }
        sort(mpp.begin(), mpp.end(), greater<pair<int, int>>());
        for(auto mp:mpp){
            if(k>0){
                ans+=mp.first;
                k--;
            }else{
                break;
            }
        }
        return ans;
    }
    
};