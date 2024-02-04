class Solution {
public:
    int solve(string s, string g) {
        if (s.length() < g.length()) {
            return -1;
        } else {
            for (int i = 0; i <= s.length() - g.length(); i++) {
                int j = 0;
                while (j < g.length() && s[i + j] == g[j]) {
                    j++;
                }
                if (j == g.length()) {
                    return i;
                }
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        int ans = solve(haystack, needle);
        return ans;
    }
};