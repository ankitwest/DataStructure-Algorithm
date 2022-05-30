

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> lis;
        for(auto env:envelopes){
            int height = env[1];
            int idx = lower_bound(lis.begin(),lis.end(),height) - lis.begin();
            if(idx==lis.size()) lis.push_back(height);
            lis[idx] = height;
        }
        return lis.size();
    }
};

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> lis;
        for(auto env:envelopes){
            int height = env[1];
            int l = 0, h = lis.size()-1; 
            while(l<=h){
                int mid = (l+h)>>1;
                if(height > lis[mid]) l = mid+1;
                else  h = mid-1;
            }
            int idx = l;
            if(idx==lis.size()) lis.push_back(height);
            lis[idx] = height;
        }
        return lis.size();
    }
};

 // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
// sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
// Now, we only need to care about width
// So, as of now we only need to look upon v[i][1]

// [ 6, 1, 8, 5, 7, 3, 8 ]
// 6    1     1,8    1,5   1,5,7   1,3,7   1,3,7,8  size = 4
// ans => 2,1 4,5 5,7 7,8
