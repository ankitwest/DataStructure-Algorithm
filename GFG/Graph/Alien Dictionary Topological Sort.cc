class Solution1
{
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node]=1;
        for(auto it:adj[node]) {
            if(!vis[it]) dfs(it, vis, st, adj);
        }
        st.push(node);
    }

public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[26];
        for(int i=0; i<N-1; i++) 
        {
            string a = dict[i];
            string b = dict[i+1];
            for(int j=0; j<min(a.size(), b.size()); j++) 
            {
                if(a[j] != b[j]) 
                {
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        
        //topo_sort code
        vector<bool> vis(26,false);
        stack<int> st;
        for(int i=0; i<26; i++) {
            if(!vis[i]) 
                dfs(i, vis, st, adj); 
        }
        
        string ans = "";
       while(!st.empty()){
           ans += (char) (st.top()+'a');
           st.pop();
       }
      return ans;
    }
};


class Solution {
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[26];     //K     // Making graph
        for(int i=0; i<N-1; i++)  
        {
           string a =  dict[i];
           string b = dict[i+1];
           for(int j=0; j<min(a.size(), b.size()); j++)
           {
               if(a[j]!=b[j])
                {
                  adj[a[j]-'a'].push_back(b[j]-'a');
                  break;
                }
           }
        }
        
        vector<int>in_degree(26, 0);  //K  // Calculating Indegree
        for(auto node : adj){
           for(auto child : node){
               in_degree[child]++;
           }
        }
        
        queue<int>q;            // pushing node with in_degree into the queue
        for(int i=0; i<26; i++){  //K
            if(in_degree[i]==0)
                q.push(i);
        }
        
        string ans = "";      // Topo Sort
        while(!q.empty())
        {
           int node = q.front(); q.pop();
           ans += (node + 'a');
           for(auto ch : adj[node])
           {
               in_degree[ch]--;
               if(in_degree[ch]==0) q.push(ch);
           }
        }
        
        return ans;
    }
};
