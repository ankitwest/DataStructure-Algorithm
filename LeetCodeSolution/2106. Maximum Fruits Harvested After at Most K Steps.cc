class Solution {
public:
     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=0,r=0; int n = fruits.size();
        while(l<n and fruits[l][0] + k < startPos)
            l++;

        int maxi = 0; int sum = 0;

        for(int r = l;r<n and fruits[r][0]<= startPos+k ;r++){
            sum += fruits[r][1];
            
            while(min(startPos-fruits[l][0]+fruits[r][0]-fruits[l][0] , fruits[r][0]-startPos+fruits[r][0]-fruits[l][0])>k){
               sum -= fruits[l][1];
                l++;
            }
            maxi = max(maxi,sum);
         }
         return maxi;
     }
};
