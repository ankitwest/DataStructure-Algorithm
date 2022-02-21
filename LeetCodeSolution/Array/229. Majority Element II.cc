class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int num1 = -1;int num2 = -1;int cnt1=0; int cnt2=0;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i]==num1) cnt1++;
            else if(a[i]==num2) cnt2++;
            else if(cnt1==0) num1 = a[i],cnt1=1;
            else if(cnt2==0) num2 = a[i],cnt2=1;
            else cnt1--,cnt2--;
        }
        
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(num1==a[i]) cnt1++;
            else if(num2==a[i]) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(num1);
        if(cnt2>n/3) ans.push_back(num2);
        
        return ans;
    }
};



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
