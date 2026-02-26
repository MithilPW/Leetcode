class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;
    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];
        
        vector<string> result;
        
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        
        for (const string& word : dict) {
            if (s.substr(0, word.size()) == word) {
                string remaining = s.substr(word.size());
                vector<string> subSentences = dfs(remaining);
                
                for (const string& sub : subSentences) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        
        return memo[s] = result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};