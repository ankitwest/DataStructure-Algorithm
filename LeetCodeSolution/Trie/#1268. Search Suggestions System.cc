
class Node {
public:
    bool end;
    vector<Node*> ch;
	
    Node(): end(false), ch(26, nullptr) {}  
};

class Trie {
public:
    Node *head = new Node();

    void insertWord(string &s) {
        Node *curr = head;
        for (char c: s) {
            if (!curr->ch[c - 'a']) 
                curr->ch[c - 'a'] = new Node();
            curr = curr->ch[c - 'a'];
        }
        curr->end = true;
    }

    vector<string> wordsBeginWith(string &prefix) {
        vector<string> temp;
        Node *curr = head;
        for (char c: prefix) {
            if (!curr->ch[c - 'a']) return {};
            curr = curr->ch[c - 'a'];
        }
        dfs(curr, temp, prefix);
        return temp;
    }

    static void dfs(Node *curr, vector<string> &temp, string &wordNow) {
        if (temp.size() == 3) 
            return;
        if (curr->end) 
            temp.push_back(wordNow);
        for (int i = 0; i < 26; ++i) {
            if (curr->ch[i]) {
                wordNow.push_back((char) ('a' + i));
                dfs(curr->ch[i], temp, wordNow);
                wordNow.pop_back();
            }
        }
    }
};

//185ms
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        Trie trie = Trie();
        for (auto &name: products) 
            trie.insertWord(name);
        
        
        string prefix = "";
        vector<vector<string>> ans;
        for (char c: searchWord) {
            prefix.push_back(c);
            ans.push_back(trie.wordsBeginWith(prefix));
        }
        return ans;
    }
};



//simple

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        
        for(int i=1;i<=searchWord.size();i++){
            int k = 3;
            vector<string> temp;
            string prefix = searchWord.substr(0,i);
            for(auto s : products){
                if(s.substr(0,i)==prefix){
                    temp.push_back(s);
                    k--;
                }
                if(k==0) break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
