class TrieNode{
    public:
        unordered_map<char,TrieNode*>mpp;
        bool endOfWord=false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root =new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->mpp.find(c)==curr->mpp.end()){
                curr->mpp[c]=new TrieNode();

            }
            curr=curr->mpp[c];
        }
        curr->endOfWord=true;
        
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->mpp.find(c)==curr->mpp.end()) return false;
            curr=curr->mpp[c];
        }
       
        return curr->endOfWord;        
    }
    
    bool startsWith(string prefix) {
        TrieNode*curr=root;
        for(char c:prefix){
            if(curr->mpp.find(c)==curr->mpp.end()) return false;
            curr=curr->mpp[c];
        }
        return true;
        
        
    }
};
