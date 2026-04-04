class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map <string , int > seqCount; // stores exactly 10 sized sequence

        vector<string> ans;

        if(s.size() < 10){
            return {};
        }

        for(int i = 0 ; i <= s.size()-10 ; i++){
            auto currentSubstring = s.substr(i,10);
            seqCount[currentSubstring]++;
        }

        for(auto[substr,freq] : seqCount){
            if(freq > 1){
                ans.push_back(substr);
            }
        }

        return ans;



    }
};