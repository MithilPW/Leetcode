class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;

            // Step 1: Find how many words fit in this line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Step 2: If last line OR only one word → left justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1)
                        line += " ";
                }

                // Fill remaining spaces at end
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                // Step 3: Fully justify
                int totalWordsLength = 0;
                for (int k = i; k < j; k++)
                    totalWordsLength += words[k].length();

                int totalSpaces = maxWidth - totalWordsLength;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(spacePerGap + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0)
                            extraSpaces--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};