class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int size = 0;  // Initialize size to 0
        int n = nums.size();
        int ans = INT_MAX;  // Initialize ans with a large value

        while (j < n) {
            if (sum < target) {
                sum += nums[j];
                j++;
                size++;
            } else {
                ans = min(size, ans);
                sum -= nums[i];
                i++;
                size--;
            }

            // Check if a valid subarray with sum >= target is found
            while (sum >= target) {
                ans = min(size, ans);
                sum -= nums[i];
                i++;
                size--;
            }
        }

        // Check if a valid subarray with sum >= target is found
        if (ans == INT_MAX) {
            return 0;  // No valid subarray found
        }

        return ans;
    }
};
