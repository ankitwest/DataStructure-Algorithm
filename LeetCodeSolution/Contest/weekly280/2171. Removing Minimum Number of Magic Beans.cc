class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end()); int n = beans.size();
        long long int sum = accumulate(beans.begin(),beans.end(),0LL);
        
        long long mini = 1e18;
        long long change=0;
        for(int i=0;i<n;i++){
           change = sum - (n-i)*(long long)(beans[i]);
            mini = min(mini,change);
        }
        return mini;
    }
};


Example 2:

Input: beans = [2,10,3,2]
Output: 7
Explanation:
- We remove 2 beans from one of the bags with 2 beans.
  This results in the remaining bags: [0,10,3,2]
- Then we remove 2 beans from the other bag with 2 beans.
  This results in the remaining bags: [0,10,3,0]
- Then we remove 3 beans from the bag with 3 beans. 
  This results in the remaining bags: [0,10,0,0]
We removed a total of 2 + 2 + 3 = 7 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that removes 7 beans or fewer.
