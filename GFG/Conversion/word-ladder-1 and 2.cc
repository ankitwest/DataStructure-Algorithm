
127. Word Ladder
https://practice.geeksforgeeks.org/problems/word-ladder/0?category%5B%5D=BFS&page=1&query=category%5B%5DBFSpage1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(auto i : wordList)
            dict.insert(i);
        if(dict.find(endWord)==dict.end()) return 0;
        
        queue<string> q; int ladder = 1;
        q.push(beginWord);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front(); q.pop();
                if(curr == endWord)
                    return ladder;
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c = 'a'; c<= 'z';c++){
                        temp[i] = c;
                        if(temp==curr) continue;
                        if(dict.find(temp)!=dict.end()){
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};




126. Word Ladder II


class Solution {
public:
    vector<vector<string>> ans;
    void dfs(string begin, string end,unordered_map< string, vector<string> >& adj,vector<string> v){
        v.push_back(begin);
        if(begin == end){
            ans.push_back(v);
            return;
        }
        for(auto w : adj[begin])
            dfs(w,end,adj,v);
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(auto i : wordList)
            dict.insert(i);
        if(dict.find(endWord)==dict.end()) return {};
        
        unordered_map<string,int> vis;
        unordered_map< string, vector<string> > adj;
        
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto curr = q.front(); q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c = 'a'; c<= 'z';c++){
                        temp[i] = c;
                        if(temp==curr) continue;
                        if(dict.find(temp) != dict.end()){
                            if(vis.find(temp) == vis.end()){
                                vis[temp] = vis[curr] + 1;
                                q.push(temp);
                                adj[curr].push_back(temp);
                            }else if(vis[temp] == vis[curr] + 1){
                                adj[curr].push_back(temp);
                            }
                        }
                    }
                }
            }
        }
        dfs(beginWord,endWord,adj,{});
        return ans;
    }
};

//similar to word ladder 1 ; with dfs to find all path
