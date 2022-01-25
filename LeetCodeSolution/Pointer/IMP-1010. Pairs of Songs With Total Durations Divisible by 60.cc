class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            time[i] %= 60;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(m.count((60-time[i])%60)>0){
                ans += m[(60-time[i])%60];
                // m[(60-time[i])%60]--;    //for single use
            }
            m[time[i]]++;
        }
        return ans;
    }
 };
 
 
 Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60


Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
