class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans;


        while(columnNumber > 0){

            columnNumber--;                

            int f = columnNumber % 26;     
            char ch = 'A' + f;           
            ans.push_back(ch);             

            columnNumber = columnNumber / 26; 
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
