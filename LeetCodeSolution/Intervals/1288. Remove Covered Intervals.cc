
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
            vp.push_back({intervals[i][0],intervals[i][1]});
        
        auto comp = [](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        };
        auto comp2 = [](pair<int,int> &a,pair<int,int> &b){
            return a.first<b.first;
        };
        
        sort(vp.begin(),vp.end(),comp);
        sort(vp.begin(),vp.end(),comp2);
            
        int ctr=1;
        int l = vp[0].first;
        int r = vp[0].second;
        for(int i=1;i<n;i++){
            if(vp[i].second<=r) continue;
            else{
                r = vp[i].second;
                ctr++;
            }
        }
        return ctr;
    }
};

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
