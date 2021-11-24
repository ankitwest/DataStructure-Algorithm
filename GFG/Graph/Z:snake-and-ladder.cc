class Solution{
  public:
    int minThrow(int n, int arr[]){
        map<int,int>m;
        vector<int> vis(31,0);
        
        for(int i=0;i<2*n;i+=2){
            if(arr[i+1]>arr[i])
            m[arr[i]]=arr[i+1];
        }
        int d[]={1,2,3,4,5,6};
        
        queue<pair<int,int>> q;
        int ans=0;
        q.push({1,0});   vis[1]=1;
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int pos = p.first;  
                ans = p.second;
                if(pos==30) return ans;
            for(int k=0;k<6;k++){
                int new_pos=pos+d[k];
                if(new_pos>=1 and new_pos<=30 and !vis[new_pos]){
                    if(m.find(new_pos)!=m.end() and !vis[m[new_pos]]){
                        vis[new_pos]=1;
                        vis[m[new_pos]]=1;
                        q.push({m[new_pos],ans+1});
                    }else{
                        vis[new_pos]=1;
                        q.push({new_pos,ans+1});
                    }
                }
            }
        }
        return -1;
    }
};
Expected Time Complexity: O(N)
