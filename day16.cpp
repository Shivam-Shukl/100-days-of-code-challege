class Solution {
private:
    void find(vector<int> &nums, int index, int size, vector<vector<int>> &ans) {
        if (index == size) {
            ans.push_back(nums); 
            return;
        }
        for (int i = index; i < size; i++) {
            swap(nums[i], nums[index]);
            find(nums, index + 1, size, ans);
            swap(nums[i], nums[index]); 
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        find(nums, 0, n, ans);
        return ans;
    }
};