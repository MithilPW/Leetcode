class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> ans;

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for (string word : words) {

            char first = tolower(word[0]);
            string currentRow;

            if (row1.find(first) != string::npos)
                currentRow = row1;
            else if (row2.find(first) != string::npos)
                currentRow = row2;
            else
                currentRow = row3;

            bool valid = true;
            for (char ch : word) {
                ch = tolower(ch);
                if (currentRow.find(ch) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};
