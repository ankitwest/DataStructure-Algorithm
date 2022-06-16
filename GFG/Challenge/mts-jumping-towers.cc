class Solution{
public:
    int solve(int n, int x, vector<int> &arr) {
        stack<int> st;
        vector<vector<int>> adj(n);
         vector<int> pre(n,-1);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]>=arr[st.top()])
                st.pop();
            if(st.empty()) pre[i] = -1;
            else {
                pre[i] = st.top();
                adj[i].push_back(st.top());
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // st = stack<int>();
        vector<int> nre(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[i]>=arr[st.top()])
                st.pop();
            if(st.empty()) nre[i] = n;
            else {
                nre[i] = st.top();
                 adj[i].push_back(st.top());
            }
            st.push(i);
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        
        int src = x;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            // int dis = pq.top().first;
            int u = pq.top().second; pq.pop();
            
            for(auto neigh : adj[u]){
                    int v = neigh;
                    int wt = 1;
                
                if(dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        // for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        // cout<<endl;
        
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];
    }
    
    };
    
    Input:
N = 4
X = 0
A[] = {1, 2, 4, 7}
Output: 3
Explanation: In first step you 
can go to index 1 from 0.In 
second step you can go to index 
2 and in third step you can go 
to index 3 from 2.  
