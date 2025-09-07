class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
        }
        for (int i = 0; i < n; i++) {
            if (i < ones - 1) {
                s[i] = '1';       
            } else if (i == n - 1) {
                s[i] = '1';      
            } else {
                s[i] = '0';      
            }
        }
        return s;
    }
};