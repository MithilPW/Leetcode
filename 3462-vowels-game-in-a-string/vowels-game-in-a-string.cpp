class Solution {
public:
    bool doesAliceWin(string s) {

        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                return true;  
            }
        }
        return false;  
    }
};
