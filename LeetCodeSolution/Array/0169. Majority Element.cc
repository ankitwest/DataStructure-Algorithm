class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        int maj_index = 0; int cnt = 1;
        for(int i=0;i<n;i++){
            if(a[maj_index]==a[i]) cnt++;
            else cnt--;
            
            if(cnt==0) maj_index = i, cnt=1;
        }
        
        int ctr=0;
        for(int i=0;i<n;i++){
            if(a[maj_index]==a[i]) ctr++;
            if(ctr>n/2) return a[maj_index];
        }
        return -1;
    }
};

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
