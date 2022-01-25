class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_tank=0; 
        int n = gas.size();
        int sum = accumulate(gas.begin(),gas.end(),0) - accumulate(cost.begin(),cost.end(),0);
        
        if(sum<0) return -1;
        
        int start = 0;
        for(int i=0;i<n;i++){
            gas_tank += gas[i]-cost[i];
            if(gas_tank<0){
                start = i+1;
                gas_tank=0;
            }
        }
        return start==n?-1:start;
    }
};
