// Problem Link : https://leetcode.com/problems/implement-trie-prefix-tree
// Difficulty: Medium

struct TrieNode{
    TrieNode* child[26] = {NULL};
    bool isleaf = false;
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for(char c:word){
            int posid = c - 'a';
            if(curr->child[posid] == NULL){
                curr->child[posid] = new TrieNode();
            }
            curr = curr->child[posid];
        }
        curr->isleaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for(char c: word){
            int posid = c - 'a';
            if(curr->child[posid] == NULL){
                return 0;
            }
            curr = curr->child[posid];
        }
        return (curr->isleaf);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c: prefix){
            int posid = c - 'a';
            if(curr->child[posid] == NULL){
                return 0;
            }
            curr = curr->child[posid];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */