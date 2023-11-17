class Solution {
private:
    void Solve(string digit, string output, int index, vector<string>& ans, vector<string>& mapping) {
        //base case
        if (index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = mapping[number];
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            Solve(digit, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        Solve(digits, output, index, ans, mapping);
        return ans;
    }
};