

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0; int j=n-1;
        int ans=0;
        while(i<j){
            int lh = height[i];
            int rh = height[j];
            int waterHeight = min(lh,rh);
            ans = max(ans,waterHeight*(j-i));
            if(lh<rh) i++;
            else j--;
        }
        return ans;
    }
};



Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
