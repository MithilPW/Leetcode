class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<unordered_set<int>> langset(m+1);
        for(int i=0;i<m;i++){
            for(int lang : languages[i]){
                langset[i+1].insert(lang);
            }
        }

        unordered_set<int> candidates;
        for(auto &f : friendships){
            int u = f[0],v = f[1];
            bool canCommunicate = false;
            for(int lang: langset[u]){
                if(langset[v].count(lang)){
                    canCommunicate = true;
                    break;
                }
            }
            if(!canCommunicate){
                candidates.insert(u);
                candidates.insert(v);
            }
        }

        if(candidates.empty()) return 0;
        vector<int> freq(n + 1, 0);
        for (int user : candidates) {
            for (int lang : langset[user]) {
                freq[lang]++;
            }
        }
        int maxFreq = 0;
        for (int lang = 1; lang <= n; lang++) {
            maxFreq = max(maxFreq, freq[lang]);
        }
        return candidates.size() - maxFreq;
    }
};