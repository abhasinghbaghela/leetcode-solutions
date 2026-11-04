class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        vector<string>nums1(n/2);
        for(int i=0;i<n-1;i+=2){
            nums1[i/2]=to_string(nums[i])+to_string(nums[i+1]);
        }
        int mini=INT_MAX;
        for(int i=0;i<n/2;i++){
            mini=min(stoi(nums1[i]),mini);
        }
        return mini;
    }
};