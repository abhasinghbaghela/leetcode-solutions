class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                mx=max(mx,nums[i]);
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans-nums[i]+mx;
        }
        return ans;
    }
};