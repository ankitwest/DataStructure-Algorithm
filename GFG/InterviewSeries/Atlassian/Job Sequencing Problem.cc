class Solution{
public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i].profit,arr[i].dead});
        }
        // auto sortbyfirst = [](pair<int,int> &a, pair<int,int> &b){
        //     if(a.first==b.first) return a.second<b.second;
        //     return a.first>b.first;
        // };
        // sort(vp.begin(),vp.end(),sortbyfirst);
        
        sort(vp.rbegin(),vp.rend());
        vector<int> vis(101,0);
        
        int ans=0; int ctr=0;
        for(int i=0;i<vp.size();i++){
            int prof = vp[i].first;
            int last = vp[i].second;
            for(int j=last;j>=1;j--){
                if(vis[j]==0) {
                    ctr++;ans += prof;
                    vis[j]=1;
                    break;
                }
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
