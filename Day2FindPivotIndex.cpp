class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int totalSum = 0; 

        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
        
            int rightSum = totalSum - leftSum - nums[i];

        
            if (leftSum == rightSum) {
                return i; 
            }

            leftSum += nums[i];
        }

        return -1; 
    }
};    
   