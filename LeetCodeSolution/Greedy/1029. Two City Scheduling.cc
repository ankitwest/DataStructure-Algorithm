class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0; int n = costs.size(); 
        vector<int> diff;
        for(int i=0;i<n;i++){
            cost += costs[i][0];
            diff.push_back({costs[i][1]-costs[i][0]});
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n/2;i++){
            cost += diff[i];
        }
        return cost;
    }
};
