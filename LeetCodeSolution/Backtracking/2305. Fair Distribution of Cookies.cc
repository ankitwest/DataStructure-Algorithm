class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>& cookies,int start, vector<int> &bag, int k){
        if(start==cookies.size()){
            int maxi = 0;
            for(auto e : bag){
                maxi = max(maxi, e);
            }
            ans = min(ans,maxi);
            return;
        }
        for(int i=0;i<k;i++){
            bag[i] += cookies[start];
            solve(cookies,start+1,bag,k);
            bag[i] -= cookies[start];
        }
        return ;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bag(k);
        int n = cookies.size();
        solve(cookies,0,bag,k);
        return ans;
    }
};
nput: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
