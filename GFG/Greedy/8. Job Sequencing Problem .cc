class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b){
        if(a.profit==b.profit){
            return a.dead>b.dead;
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
            int d = arr[i].dead;
            for(int j=d;j>=1;j--){
                if(vis[j]==0) {vis[j]=1,ans+=arr[i].profit,ctr++; break;}
            }
        }
        return {ctr,ans};
    } 
    };

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
