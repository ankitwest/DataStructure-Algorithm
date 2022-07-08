// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k){
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<k;i++)
            m[a[i]]++;
        ans.push_back(m.size());
            
        int left = 0;
        for(int i=k;i<n;i++){
            if(m[a[left]]==1)
                m.erase(a[left]);
            else
                m[a[left]]--;
            m[a[i]]++;
            ans.push_back(m.size());
            left++;
        }
        
        return ans;
    }
};


