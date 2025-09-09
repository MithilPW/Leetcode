class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); 
        dp[1] = 1;

        for (int day = 1; day <= n; day++) {
            long long people = dp[day] % MOD;

            for (int next = day + delay; next < day + forget && next <= n; next++) {
                dp[next] = (dp[next] + people) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans; 
    }
};