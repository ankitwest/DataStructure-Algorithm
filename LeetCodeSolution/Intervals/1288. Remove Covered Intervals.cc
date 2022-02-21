
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

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        
        int r = intervals[0][1];
        int ctr=1;
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=r) continue;
            else {
                r = intervals[i][1];
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

    
    
    
class Solution {
public:
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int ctr=1; 
        int l = intervals[0][0]; int r = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>l and intervals[i][1]>r){
                l = intervals[i][0];
                ctr++;
            }
            r = max(r,intervals[i][1]);
        }
        return ctr;
        }
};
