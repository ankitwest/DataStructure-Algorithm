class Trie{
public:
    string word;
    int endsHere;
    Trie* child[26];
    Trie(){
        word = "";
        endsHere = 0;
        for(int i=0;i<26;++i)
            child[i]=NULL;
    }
};
class Solution {
public:
    vector<string> ans;
    void insert(Trie* head,string s){
        Trie* root = head;
        for(auto &i:s){
            int k=i-'a';
            if(root->child[k]==NULL){
                root->child[k]=new Trie();
            }
            root=root->child[k];
        }
        root->word=s;
        root->endsHere=true;
    }
    
    void dfs(vector<vector<char>>& board,Trie* root,int i, int j){
          if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='*' || !(root->child[board[i][j]-'a']))
            return;
        
        root=root->child[board[i][j]-'a'];
        
        if(root->endsHere>0){
            ans.push_back(root->word);
            root->endsHere = 0;
        }
        
        char ch = board[i][j];
        board[i][j] = '*';    // marking vis
        
        dfs(board,root,i+1,j);
        dfs(board,root,i-1,j);
        dfs(board,root,i,j+1);
        dfs(board,root,i,j-1);
        
        board[i][j] = ch;     // backtracking
    }
    int n,m;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {  
        n = board.size(); m = board[0].size();
        
        Trie* head = new Trie();
        for(auto s:words)
            insert(head,s);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs(board,head,i,j);
        
        return ans;
    }
};
