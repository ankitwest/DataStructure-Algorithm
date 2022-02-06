class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(); vector<int> left(n,0),right(n,0); 
        
        left[0] = s[0]=='1';
        for(int i=1;i<n;i++){
            if(s[i]=='1') left[i] = min(left[i-1]+2,i+1);
            else if(s[i]=='0') left[i]=left[i-1];
        }
        right[n-1] = s[n-1]=='1';
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1') right[i] = min(right[i+1]+2,n-i);
            else if(s[i]=='0') right[i]=right[i+1];
        }
        
        int ans = min(left[n-1],right[0]);
        for(int i=0;i<=n-2;i++){
            ans = min(left[i]+right[i+1],ans);
        }
        return ans;
    }
};

Input: s = "1100101"
Output: 5
Explanation: 
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end. Time taken is 1.
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2 + 1 + 2 = 5. 

An alternative way is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
This also obtains a total time of 2 + 3 = 5.

5 is the minimum time taken to remove all the cars containing illegal goods. 
There are no other ways to remove them with less time.
