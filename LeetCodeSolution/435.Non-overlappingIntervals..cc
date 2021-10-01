class Solution {
public:
static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans =0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
      
        vector<int> prev; prev=intervals[0];
        for(int i=1;i<n;i++){
            if(prev[1]>intervals[i][0])
                ans++;
            else
                prev=intervals[i];
        }
        return ans;
    }
};
