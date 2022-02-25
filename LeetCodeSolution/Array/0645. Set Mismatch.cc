

class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
         int x=0; 
        vector<int> v;
        for(int i=0;i<a.size();i++){
            if(a[abs(a[i])-1]<0) v.push_back(abs(a[i]));
            else x = a[abs(a[i])-1], x*= -1 , a[abs(a[i])-1]=x;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]>0) v.push_back(i+1);
        }
         return v;
    }
};

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
