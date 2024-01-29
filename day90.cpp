class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < t.length()) {
            if (j == s.length()) {
                break;
            }

            if (t[i] == s[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == s.length();
    }
};
