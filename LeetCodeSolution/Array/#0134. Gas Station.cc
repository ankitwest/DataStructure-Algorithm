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

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
