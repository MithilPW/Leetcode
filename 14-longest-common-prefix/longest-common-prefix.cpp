class TrieNode{
    public:
            char data;
            unordered_map<char, TrieNode*> children;
            bool isTerminal;
            int childCount;
            TrieNode(int val) {
                data = val;
                isTerminal = false;
                childCount = 0;
            }

};
class Solution {
public:
    void insertWord(TrieNode* root, string str){
        if(str.length() == 0){
            root->isTerminal = true;
            return;
        }
        char ch = str[0];
        TrieNode* child;
        if(root -> children.find(ch) != root->children.end()){
            //present
            child = root -> children[ch];
        }
        else{
            //absent - current node pr ek child add karna h
            child = new TrieNode(ch);
            root->children[ch] = child;
            root->childCount++;
        }

        insertWord(child,str.substr(1));
    }
    string findLCP(TrieNode* root,string word){
        string ans ="";

        if(root -> isTerminal){
            return ans;
        }

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(root -> childCount == 1){
                ans.push_back(ch);
                root = root -> children[ch];
            }
            else{
                break;
            }

            if(root -> isTerminal){
                break;
            }
        }
        return ans;
        // TrieNode* temp = root;
        // while(temp -> childCount == 1){
        //     ans.push_back(temp->data);
        //     //move to non null wala child

        //     for(auto i: temp->children){
        //         if(i.second != NULL){
        //             temp = i.second;
        //         }
        //     }
        // }
        // return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(int i = 0 ; i<strs.size();i++){
            string str = strs[i];
            insertWord(root,str);
        }
        string ans = findLCP(root,strs[0]);
        return ans;
        // if(strs.empty()) return "";

        // string result;
        // string s1 = strs[0];

        // for(int i = 0; i < s1.size(); i++) {
        //     char c = s1[i];

        //     // check this char with all other strings
        //     for(int j = 1; j < strs.size(); j++) {
        //         if(i >= strs[j].size() || strs[j][i] != c) {
        //             return result; // mismatch found
        //         }
        //     }
        //     result.push_back(c); // common char
        // }
        // return result;
        // if(str.empty()){
        //     return "";  
        // }
        //  string s1 = str[0]; 

        //  string s2 = str[1]; 

        //  string s3 = str[2];


        // string result;

        // for(int i=0;i<s1.size();i++){
        //     char c = s1[i]
        //     if(s1[i] == s2[i] && s2[i] == s3[i]){
        //     }
            
        // }
        // return result;
    }
};