class Solution{
  public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b){
        if(a.profit==b.profit){
            return a.dead<b.dead;
        }
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        
        int vis[101];
        memset(vis,0,sizeof(vis));
        int ans=0; int ctr=0;
        
        for(int i=0;i<n;i++){
            // int d = arr[i].dead;
            for(int j = arr[i].dead; j>=1;j--){
                if(vis[j]==0) {
                    vis[j]=1,ans+=arr[i].profit,ctr++; 
                    break;
                }
            }
        }
        return {ctr,ans};
    } 
};
