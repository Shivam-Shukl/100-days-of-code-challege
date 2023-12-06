#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        queue<int> q;

        int ans = -1; // Initialize ans with -1
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            count[ch]++;
            q.push(i); 
        }
        while (!q.empty()) {
            int index = q.front();
            if (count[s[index]] > 1) {
                q.pop();
            } else {
                ans = index; // Store the index of the first unique character
                break;
            }
        }
        return ans;
    }
};
