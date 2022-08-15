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





// Word Ladder 2

// TLE now , test cases updated
class Solution11 {
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











// Word Ladder 2 , correct
class Solution
{
    int difference(const string &a, const string &b){
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                diff++;
        return diff;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        int endIndex = -1;
        vector<vector<int>> graph(n);

		// Create graph using indices to avoid string comparisons
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if (difference(wordList[i], wordList[j]) == 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
            if (wordList[i] == endWord)
                endIndex = i;
        }
		
		// No need to run BFS if the endWord is not found in wordList
        if (endIndex == -1)
            return {};

        vector<vector<string>> ans;
        vector<int> dist(n, INT_MAX);
        vector<unordered_set<int>> parent(n);
        queue<int> q;

        for (int i = 0; i < wordList.size(); i++)
        {
            if (difference(wordList[i], beginWord) == 1)
            {
                q.push(i);
                dist[i] = 0;
            }
        }

        bool ansFound = false;

        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            if (x == endIndex)
            {
                ansFound = true;
            }
            for (auto &it : graph[x])
            {
                if (dist[it] == INT_MAX)
                {
                    dist[it] = dist[x] + 1;
                    q.push(it);
                    parent[it].insert(x);
                }
                else if (dist[it] == dist[x] + 1)
                {
                    parent[it].insert(x);
                }
            }
        }

        vector<string> path = {};

        auto generateAns = [&](const auto generateAns,int index)->void{
            path.push_back(wordList[index]);
            if (parent[index].empty())
            {
                ans.push_back(path);
            }

            for (auto &it : parent[index])
                generateAns(generateAns,it);

            path.pop_back();
        };
        if (ansFound)
        {
            generateAns(generateAns,endIndex);
            for (auto &v : ans)
            {
                v.push_back(beginWord);
                reverse(v.begin(), v.end());
            }
        }
        return ans;
    }
};

/*
Go from the Endword to the BeginWord not the opposite
Do the BFS layer by layer. But use set instead of deque
*/

//similar to word ladder 1 ; with dfs to find all path
