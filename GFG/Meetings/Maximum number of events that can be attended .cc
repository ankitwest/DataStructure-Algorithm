 int maxEvents(int start[], int end[], int n) {
        vector<pair<int,int>> vp;
       unordered_set<int>s;
       for(int i=0;i<n;i++)
          vp.push_back({start[i],end[i]});
       sort(vp.begin(),vp.end());
       
       for(int i=n-1;i>=0;i--){
           if(s.find(vp[i].second)==s.end())
                s.insert(vp[i].second);
            else{
                int e = vp[i].second;
                while(e>=vp[i].first){
                    if(s.find(e)==s.end()) { s.insert(e); break;}
                    e--;
                }
            }
       }
       return s.size();
    }




Input:
N = 3
start[] = {1, 2, 1}
end[] = {1, 2, 2}
Output:
2
Explanation:
You can attend a maximum of two events.
You can attend 2 events by attending 1st event
at Day 1 and 2nd event at Day 2.
Example 2:
Input:
N = 3
start[i] = {1, 2, 3}
end[i] = {2, 3, 4} 
Output :
3
Explanation:
You can attend all events by attending event 1
at Day 1, event 2 at Day 2, and event 3 at Day 3.
