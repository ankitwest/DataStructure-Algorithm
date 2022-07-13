class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(auto i:answers)
            m[i]++;
        
        int ans = 0;
        for(auto [x,y]:m){
            int grp_sz = x+1;
            int no_grp = y/grp_sz; 
            no_grp += y % grp_sz ? 1 : 0;
            ans += no_grp * grp_sz;
        }
        return ans;
    }
};

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
