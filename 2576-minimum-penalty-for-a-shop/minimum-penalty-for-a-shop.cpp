class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = count(customers.begin(), customers.end(), 'Y'); 
        // initial penalty if closed at hour 0 (all 'Y' are closed)

        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--; // now open, so fewer closed 'Y'
            } else { // customers[i] == 'N'
                penalty++; // now open, so more open 'N'
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1; // closing after this hour
            }
        }

        return bestHour;
    }
};
