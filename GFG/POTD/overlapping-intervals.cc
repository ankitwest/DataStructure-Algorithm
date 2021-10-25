class Solution{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {

         vector<vector<int>> vv;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int start,end;
        int i=0;
        while(i<n){
           start = intervals[i][0];
            end = intervals[i][1];
            while(i<n-1 and intervals[i+1][0] <= end){
                end = max(end,intervals[i+1][1]);
                  i++; 
            }
            vv.push_back({start,end});
            i++;
        }
        return vv;
    }
};



Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(Log(N)) or O(N).
  
  
  
class Solution{ 
 public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>> vv;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int si = intervals[0][0]; 
        int ei = intervals[0][1]; 
        for(int i=1;i<n;i++){
            int sf = intervals[i][0]; int ef = intervals[i][1];
            if(sf>ei){
                vv.push_back({si,ei});
                si = sf; ei = ef;
            }else{
                ei = max(ei,ef);
            }
        }
        vv.push_back({si,ei});
        return vv;
        
    }
};



