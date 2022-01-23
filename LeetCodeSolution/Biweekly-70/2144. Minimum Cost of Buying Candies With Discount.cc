class Solution {
public:
    // Approach  and Code
    
    // first we sort the array in descending order
    // and then we take  pick the first two elements and leave the 3rd one
         // do check for segemtation fault  
    int minimumCost(vector<int>& cost) {
        
        sort(cost.rbegin(),cost.rend());  
        
        
        int n = cost.size(); int ans = 0;
        
        for(int i=0;i<n;i+=3){
            if(i<n) ans += cost[i];
            if(i+1<n)  ans += cost[i+1];
        }
        return ans;
    } 
};
