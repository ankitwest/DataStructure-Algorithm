class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k){
        vector<int> ans;
        map<int,int> m1;
        for(int i=0;i<k;i++)
            m1[a[i]]++;
        ans.push_back(m1.size());
            
        int left =0;
        for(int i=k;i<n;i++){
            if(m1[a[left]]==1)
                m1.erase(a[left]);
            else
                m1[a[left]]--;
            m1[a[i]]++;
            ans.push_back(m1.size());
            left++;
        }
        
        return ans;
    }
};


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
