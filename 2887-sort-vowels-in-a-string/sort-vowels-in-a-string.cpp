class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
         vector<char> vowel;

        for(char ch : s) {
            if(isVowel(ch)) vowel.push_back(ch);
        }

        sort(vowel.begin(), vowel.end());

        int index = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowel[index++];
            }
        }

        return s;
    }
};