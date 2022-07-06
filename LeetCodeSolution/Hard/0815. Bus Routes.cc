class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int tar) {
        unordered_map<int,vector<int>> bus_ids;  //stores bus_ids at cur_stop
        for(int i=0;i<routes.size();i++){
            for(auto j : routes[i]){
                int bus_id = i;
                int stop = j;
                bus_ids[stop].push_back(bus_id);
            }
        }
        
        queue<pair<int,int>> q;
        unordered_set<int> vis;
        q.push({src,0});
        vis.insert(src);
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            auto [stop, ans] = curr;
            
            if(stop==tar) return ans;
            
            for(auto bus_id : bus_ids[stop]){
                for(auto j : routes[bus_id]){
                    if(vis.count(j)==0)
                    {
                        vis.insert(j);
                        q.push({j,ans+1});
                    }
                }
                routes[bus_id].clear();  //tle
            }
        }
        return -1;
    }
};
