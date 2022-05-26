
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
        int tap=0;int i=0;
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
            tap++;
            i++;
            target = max_further+1;
        }
        return tap;
    }
};

Input:
n = 6
gallery[ ] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: Sprinklers at index 2 and 5
can water thefull gallery, span of
sprinkler at index 2 = [0,4] and span
â€‹of sprinkler at index 5 = [5,5].
Example 2:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
Output:
-1
Explanation: No sprinkler can throw water
at index 7. Hence all plants cannot be
watered.
