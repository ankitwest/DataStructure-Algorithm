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
