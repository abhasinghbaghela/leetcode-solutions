class Solution {
public:
    void heapifyDown(int i,vector<int>&nums) {
        int n = nums.size();
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
                int right = 2 * i + 2;
            if (left < n && nums[left] > nums[largest])
                largest = left;
            if (right < n && nums[right] > nums[largest])
                largest = right;
            if (largest == i)
                break;
            swap(nums[i], nums[largest]);
            i = largest;
        }
    }
    void extractMax(vector<int>&nums){
        if (nums.empty())
            return;
        nums[0] = nums.back();
        nums.pop_back();
        if (!nums.empty())
            heapifyDown(0,nums);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i, nums);
        }
        for(int i=1;i<k;i++){
            extractMax(nums);
        }
        return nums[0];
    }
};