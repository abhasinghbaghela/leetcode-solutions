class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int pk=0;
        int vl=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                pk+=nums[i];
            }
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                vl+=nums[i];
            }
        }
        
        return pk-vl;
    }
};