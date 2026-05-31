class TrieNode{
    public:
        char data;
        unordered_map<char , TrieNode*> children;
        bool isTerminal;

        TrieNode(char val){
            data = val;
            isTerminal = false;
        }
};
void insertWord(TrieNode* root,string word){

    //base case
    //agar main saare character trie se insert kar chuka hu
    //then abhi jis node pr bhi khada hu , vo ek
    //terminal node h

    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //1case solve karo
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present -> move to their child
        child = root->children[ch];
    }

    else{
        //absent
        //create node
        child = new TrieNode(ch);
        //link
        root->children[ch] = child;
    }

    //baki recursion sambhal lega
    insertWord(child,word.substr(1));
}
bool searchWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        //yaani main last char wali node par khada hu
        return root->isTerminal;
    }
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present -> move to their child
        child = root->children[ch];
    }

    else{
        return false;
    }

    bool recursionKaAns = searchWord(child,word.substr(1));
    return recursionKaAns;

}

bool searchPrefix(TrieNode* root , string word){
     //base case
    if(word.length() == 0){
        //yaani main last char wali node par khada hu
        return true;
    }
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present -> move to their child
        child = root->children[ch];
    }

    else{
        return false;
    }

    bool recursionKaAns = searchPrefix(child,word.substr(1));
    return recursionKaAns;
}
class Trie {
public:
    TrieNode * root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        //exact search logic but without search logic
        return searchPrefix(root , prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */