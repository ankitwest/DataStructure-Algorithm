

class Solution{
    public:
int min_sprinklers(int gallery[], int n)
    {
      vector<pair<int,int>> range;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
            int left = max(i-gallery[i],0); int right = min(i+gallery[i],n-1);
            range.push_back({left,right});
            }
        }
        sort(range.begin(),range.end());
        int target=0;
        int cnt=0;int i=0;
        while(target<n){
            if(i==range.size() or range[i].first>target) 
                return -1;
                
            int max_further = range[i].second;
            while(i+1<range.size() and range[i+1].first<=target){
                i++; 
                max_further = max(max_further,range[i].second);
            }
            if(max_further<target)
                return -1;
            cnt++;
            i++;
            target = max_further+1;
        }
        return cnt;
      }
};
