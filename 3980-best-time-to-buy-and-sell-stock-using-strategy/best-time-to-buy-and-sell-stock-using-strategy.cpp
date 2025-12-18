class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        vector<long long> prefOld(n), prefPrice(n);
        

        for (int i = 0; i < n; i++) {
            long long contrib = 1LL * strategy[i] * prices[i];
            prefOld[i] = contrib + (i ? prefOld[i - 1] : 0);
            prefPrice[i] = prices[i] + (i ? prefPrice[i - 1] : 0);
        }
        
        long long originalProfit = prefOld[n - 1];
        long long bestGain = 0;
        

        for (int l = 0; l + k - 1 < n; l++) {
            int r = l + k - 1;
            
            long long oldContribution =
                prefOld[r] - (l ? prefOld[l - 1] : 0);

            int sellStart = l + k / 2;
            long long sellSum =
                prefPrice[r] - prefPrice[sellStart - 1];
            
            long long gain = sellSum - oldContribution;
            bestGain = max(bestGain, gain);
        }
        
        return originalProfit + bestGain;
    }
};
