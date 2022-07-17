class Trie {
public:
    Trie* next[2];
    Trie(){
        next[0] = NULL;
        next[1] = NULL;
    }
};
class TrieNode {
public:
    Trie* head;
    TrieNode(){
        head = new Trie();
    }
    
    void insert(int val){
        Trie* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            
            if(curr->next[bit]==NULL)
                curr->next[bit] = new Trie();
        
             curr = curr->next[bit];
        }
    }
    
    
    int find(vector<int> nums){
        int max_xorr = INT_MIN;
        
        for(auto val : nums){
            Trie* curr = head;
            int ans = 0;
            for(int i=31;i>=0;i--){
                int bit = (val>>i)&1;
                int oppo = !bit;
                if(curr->next[oppo])
                    ans = ans | (1<<i), curr = curr->next[oppo];
                else
                    curr = curr->next[!oppo];
            }
            max_xorr = max(max_xorr,ans);
        }
        return max_xorr;
    }
};
    
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // TrieNode* root = new TrieNode();   // pointer we use ->
        TrieNode root; // obj  we use .
        
        for(auto a : nums){
            root.insert(a);
        }
        return root.find(nums);
    }
};
