class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        
        int maxVowel = 0, maxCons = 0;

        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if(freq[i] == 0) continue;
            
            if(vowelSet.count(c)) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxCons = max(maxCons, freq[i]);
            }
        }
        
        return maxVowel + maxCons;
    }
};
