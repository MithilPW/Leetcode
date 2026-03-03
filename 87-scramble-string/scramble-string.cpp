class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {

        if (s1 == s2) return true;

        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        // Prune: check frequency
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return memo[key] = false;

        int n = s1.size();

        for (int k = 1; k < n; k++) {

            // Case 1: No swap
            if (isScramble(s1.substr(0, k), s2.substr(0, k)) &&
                isScramble(s1.substr(k), s2.substr(k)))
                return memo[key] = true;

            // Case 2: Swap
            if (isScramble(s1.substr(0, k), s2.substr(n - k)) &&
                isScramble(s1.substr(k), s2.substr(0, n - k)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
};