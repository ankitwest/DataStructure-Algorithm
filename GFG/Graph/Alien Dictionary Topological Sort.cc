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







class Solution{
public:
	vector<int> res;
	void findTopoSort(int node,stack<int>& st,vector<int> adj[],vector<bool>& vis)
	{
	    vis[node]=1;
	    for(auto neigh:adj[node]){
	        if(!vis[neigh])
	            findTopoSort(neigh,st,adj,vis);
	    }
	    st.push(node);
	} 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	   vector<bool> vis(V,false);
	   stack<int>st;
	   for(int i=0;i<V;i++){
	       if(!vis[i])
	        findTopoSort(i,st,adj,vis);
	   }
	   
	   while(!st.empty()){
	       int x = st.top();st.pop();
	       res.push_back(x);
	   }
	   return res;
	}
};


class Solution23
{
 public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
        vector<vector<int>> adj(n);
        vector<int> in_degree(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in_degree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_degree[i]==0) q.push(i);
        }
        
        vector<int> toposort;
        while(!q.empty())
        {
            auto node = q.front();q.pop();
            toposort.push_back(node);
            for(auto neigh:adj[node])
            {
                in_degree[neigh]--;
                if(in_degree[neigh]==0) q.push(neigh);
            }
        }
        
        if(toposort.size()==n) return toposort;
        return {};
    }
};
