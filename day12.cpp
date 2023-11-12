class Solution {
private:
    void Possible_sum(vector<int>& arr, int size, int index, int target, vector<vector<int>>& ans, vector<int>& output, int sum) {
        // base condition
        if (index == size) {
            return;
        }
        if (sum == target) {
            ans.push_back(output);
            return;
        }
        if (sum > target) {
            return;
        }

        // exclude
        Possible_sum(arr, size, index + 1, target, ans, output, sum);

        // include
        output.push_back(arr[index]);
        Possible_sum(arr, size, index, target, ans, output, sum + arr[index]);

        // remove the last element to backtrack
        output.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        Possible_sum(candidates, candidates.size(), index, target, ans, output, 0);
        return ans;
    }
};
