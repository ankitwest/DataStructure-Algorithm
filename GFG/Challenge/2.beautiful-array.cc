
Input: arr[] = {1,1,3,1,1,6,1,1,8,10}
X = 3, K = 1
Output: 2
Explanation: You can add atmost 3 elements in the original array
to make the array beautiful from the given array.
So lets say you add 2, 7 and 9 in the original array.
Now we can make two beautiful array from it.
arr1[] = {1,1,1,1,1,1,2,3}
arr2[] = {6,7,8,9,10}
So the output will be 2.


class Solution{
 public:
    int beautifulArray(vector<int>& a, int x, int k) {
        sort(a.begin(),a.end());
        vector<int> gap;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]>k) gap.push_back(a[i]-a[i-1]);
        }
         sort(gap.begin(),gap.end());
         
         int ans = gap.size()+1;
         for(int i=0;i<gap.size();i++){
             int val = gap[i];
             int req = val/k;
             if(val%k==0){
                  req--;
             }
             if(req>x){
                 break;
             }
             x -= req;
             ans--;
             if(x<=0) {
                 break;
             }
         }
         return ans;
    }
 };
