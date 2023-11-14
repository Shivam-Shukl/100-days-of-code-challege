class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int totalSum = 0; // Calculate the total sum of the array

        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0; // Initialize the left sum
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
        // Update the right sum by subtracting the current element
            int rightSum = totalSum - leftSum - nums[i];

        // Check if the left and right sums are equal
            if (leftSum == rightSum) {
                return i; // Return the pivot index
            }

            leftSum += nums[i]; // Update the left sum for the next iteration
        }

        return -1; // If no pivot index is found, return -1
    }
};    
   