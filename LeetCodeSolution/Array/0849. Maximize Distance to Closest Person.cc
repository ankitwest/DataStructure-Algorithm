class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = INT_MIN;
        int left = -1;
        
        for(int i=0;i<n;i++){
            if(seats[i]==0) continue;
            if(left==-1)
                ans = max(ans,i);
            else
                ans = max(ans,(i-left)/2);
            left = i;
        }
        if(seats[n-1]==0)
            ans = max(ans,n-1-left);
        
        return ans;
    }
};
/*
0 0 0 1 0 1
0 1 2 3 4 5
*/

// either seated wise
// or number of empty seats from front back and inbtw

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left = -1;
        int pre = -1; int suff = 0; int max_zeroes = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(seats[i]==0) cnt++;
            else{
                if(pre==-1) pre = cnt;
                else max_zeroes = max(max_zeroes,cnt);
                cnt = 0;
            }
        }
        suff = cnt;
        int ans = max({pre, suff, (max_zeroes+1)/2});
        return ans;
    }
};
