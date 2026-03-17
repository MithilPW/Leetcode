class Solution {
public:
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string,int> mp;
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            mp[words[i]] = i;
        }
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            
            string word = words[i];
            
            for(int j = 0; j <= word.size(); j++) {
                
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if(isPalindrome(word, 0, j-1)) {
                    string rev = suffix;
                    reverse(rev.begin(), rev.end());
                    
                    if(mp.count(rev) && mp[rev] != i) {
                        res.push_back({mp[rev], i});
                    }
                }
                
                if(j != word.size() && isPalindrome(word, j, word.size()-1)) {
                    string rev = prefix;
                    reverse(rev.begin(), rev.end());
                    
                    if(mp.count(rev) && mp[rev] != i) {
                        res.push_back({i, mp[rev]});
                    }
                }
            }
        }
        return res;
    }
};