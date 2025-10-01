class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;   // store indices instead of chars
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
            q.push(i);   // push index instead of character

            // Remove indices of characters that are no longer unique
            while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                q.pop();
            }
        }

        // If queue is empty, no unique char exists
        if (q.empty()) return -1;

        // Otherwise, front index is the first unique character
        return q.front();
    }
};
