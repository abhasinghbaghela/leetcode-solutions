class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int i=0;
        while(i<nums.size()){
            int j=i;
            while(j<nums.size() && nums[j]<=maxK && nums[j]>=minK){
                j++;
            }
            int l=j-i;
            ans+=1LL*l*(l+1)/2;
            i=j+1;
        }
        return ans;
    }
};