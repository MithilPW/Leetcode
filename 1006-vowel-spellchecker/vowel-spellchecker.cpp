class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;  
        unordered_map<string, string> caseMap;   
        unordered_map<string, string> vowelMap;  


        auto isVowel = [](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        auto toLower = [](string s) {
            for (char &c : s) c = tolower(c);
            return s;
        };

        auto devowel = [&](string s) {
            s = toLower(s);
            for (char &c : s) {
                if (isVowel(c)) c = '*';
            }
            return s;
        };


        for (string &word : wordlist) {
            exact.insert(word);

            string lower = toLower(word);
            if (!caseMap.count(lower)) {
                caseMap[lower] = word;
            }

            string pattern = devowel(word);
            if (!vowelMap.count(pattern)) {
                vowelMap[pattern] = word;
            }
        }

        vector<string> result;
        for (string q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
            } else {
                string lower = toLower(q);
                string pattern = devowel(q);

                if (caseMap.count(lower)) {
                    result.push_back(caseMap[lower]);
                } else if (vowelMap.count(pattern)) {
                    result.push_back(vowelMap[pattern]);
                } else {
                    result.push_back("");
                }
            }
        }
        return result;
    }
};
