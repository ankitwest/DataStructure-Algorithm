

// User function template for C++

// root : root node of the trie
// key : string to be inserted into the trie
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node

void insert(struct TrieNode *root, string key) {
    TrieNode* curr = root;
    for(int i=0;i<key.size();i++){
        if(!curr->children[key[i]-'a'])
            curr->children[key[i]-'a'] = getNode();
        curr = curr->children[key[i]-'a'];
    }
    curr->isLeaf = true;
}

// root : root node of the trie
// key : string to search in the trie
// Returns true if key presents in trie, else false

bool search(struct TrieNode *root, string key) {
    TrieNode* curr = root;
    for(int i=0;i<key.size();i++){
        if(!curr->children[key[i]-'a'])
            return false;
         curr = curr->children[key[i]-'a'];
    }
    return (curr->isLeaf);
}


Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = the
Output: 1
Explanation: the is present in the given
string "the a there answer any by bye
their"
