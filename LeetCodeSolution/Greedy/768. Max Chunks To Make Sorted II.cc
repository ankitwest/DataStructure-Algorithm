

class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int n = v.size();int cnt=0; 
        vector<int> vv = v;
        sort(vv.begin(),vv.end());
        long long sum1=0; long long sum2=0;
        for(int i=0;i<n;i++){
            sum1 += v[i];
            sum2 += vv[i];
            if(sum1==sum2) cnt++,sum1=0,sum2=0;
        }
        return cnt;
    }
};

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
