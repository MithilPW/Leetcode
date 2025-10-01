class Solution {
public:
    int firstUniqChar(string s) {
    queue<int> q;
    int freq[26] = {0};

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        freq[ch-'a']++;
        q.push(i);


        while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                q.pop();
        }
    }
    if(q.empty()){
            return -1;
        }
    return q.front();
    }
};