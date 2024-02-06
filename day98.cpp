class Solution {
private:
    bool isHappyHelper(int &n) {
        // create a set to store the seen numbers
        std::unordered_set<int> seen;
        // loop until n becomes 1 or a repeated number
        while (n != 1 && seen.find(n) == seen.end()) {
            // add n to the set
            seen.insert(n);
            // calculate the next number
            int next = 0;
            while (n > 0) {
                int x = n % 10;
                next += x * x;
                n /= 10;
            }
            n = next;
        }
        // return true if n is 1, false otherwise
        return n == 1;
    }

public:
    bool isHappy(int n) {
        return isHappyHelper(n);
    }
};
