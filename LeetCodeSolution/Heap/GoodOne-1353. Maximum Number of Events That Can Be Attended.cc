  class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
//         sort(events.begin(),events.end());
//         priority_queue<int,vector<int>,greater<int>> pq;
        
//         int ans=0; int i=0;
//         for(int d=1;d<=100000;d++){
//             while(!pq.empty() and pq.top()<d)
//                 pq.pop();
//             while(i<events.size() and events[i][0]==d){
//                 pq.push(events[i][1]); i++;
//             }
            
//             if(!pq.empty()) pq.pop(),ans++;
//         }
//         return ans;
        
        // M-2
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int ans=0; int i=0; int n = events.size(); int day=0;
        while(pq.size() or i<n){
            if(pq.size()==0)
                day = events[i][0];
            while(i<n and events[i][0]==day){
                pq.push(events[i][1]); i++;
            }
            pq.pop();
            ans++;day++;
             while(!pq.empty() and pq.top()<day)
                pq.pop();
        }
        return ans;
    }
};

Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
