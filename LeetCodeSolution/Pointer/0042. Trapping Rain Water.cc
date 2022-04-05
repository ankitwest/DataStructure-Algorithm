

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        if(n==0) return 0;
        
        int lmax[n],rmax[n];
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        int res=0;
        
         for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],height[i]);
    
        for(int i=n-2;i>=0;i--)
        rmax[i]=max(rmax[i+1],height[i]);
        
       for(int i=1;i<n-1;i++)
            res+=min(lmax[i],rmax[i])-height[i];
        
        return res;
    }
};

class Solution2{
public:
    int trap(vector<int> & height){
        int res = 0;
        int n=height.size();
        
        int lo=0,hi=n-1;
        int left_max=0,right_max=0;
        
        while(lo<=hi){
            if(height[lo]<height[hi]){
                if(height[lo]<left_max)
                    res += left_max-height[lo];
                else
                    left_max=height[lo];
                lo++;
            } else{
                if(height[hi]<right_max)
                    res+= right_max-height[hi];
                else
                    right_max=height[hi];
                hi--;
            }
        }
    return res;
    }
};


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
