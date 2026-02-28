class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        
        // Step 1: Store frequency of characters in t
        for(char c : t){
            mp[c]++;
        }
        
        int left = 0;
        int count = t.size();  // total characters needed
        int minLen = INT_MAX;
        int startIndex = 0;
        
        // Step 2: Expand window
        for(int right = 0; right < s.size(); right++){
            
            // If character is needed
            if(mp[s[right]] > 0){
                count--;
            }
            
            mp[s[right]]--;
            
            // Step 3: When window is valid
            while(count == 0){
                
                // Update minimum window
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIndex = left;
                }
                
                // Try shrinking from left
                mp[s[left]]++;
                
                if(mp[s[left]] > 0){
                    count++;
                }
                
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};