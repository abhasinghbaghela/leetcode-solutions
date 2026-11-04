class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            sum=sum/2;
        }
        vector<bool>prev(sum+1,false);
        prev[0]=true;
        if (nums[0] <=sum) {
            prev[nums[0]] = true;
        }
        for(int i=1;i<n;i++){
            vector<bool>curr(sum+1,false);
            curr[0]=true;
            for(int tar=1;tar<=sum;tar++){
                bool notTake=prev[tar];
                bool take=false;
                if(nums[i]<=tar){
                    take=prev[tar-nums[i]];
                }
                curr[tar]=take||notTake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};