 public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int>m;
        int sum = 0; int ans=0;
        m[sum] = -1;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            if(m.count(sum))
                ans = max(ans,i-m[sum]);
            else
                m[sum] = i;
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     sum += A[i];
        //     if(!m.count(sum))
        //     m[sum] = i;
          
        // }

        
        // sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=A[i];
        //     if(m.count(sum))
        //     ans=max(ans,i-m[sum]);
            
        // }
        return ans;
    }
