class Solution {
public:
    int minimumDeviation(vector<int>& arr) {
        set<int> s; int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]&1) s.insert(arr[i]*2);
            else s.insert(arr[i]);
        }
        int ans = *s.rbegin()-*s.begin();
        
        while(*s.rbegin()%2==0){
            int x = *s.rbegin();
            s.erase(x);
            s.insert(x/2);
            ans = min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};


Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3
