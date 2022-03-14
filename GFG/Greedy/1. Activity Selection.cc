class Solution{
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int> a,pair<int,int> b){
        // if(a.second==b.second)
        //     return a.first>b.first;
        return a.second<b.second;    {enough}
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),comp);
        
        int ctr=1;
        int x = vp[0].second;
        for(int i=1;i<n;i++){
            if(vp[i].first<=x) continue;
            else {
                ctr++;
                x = vp[i].second;
            }
        }
        return ctr;
    }
};
  Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
