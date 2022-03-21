  
  
  class Solution {
public:
    int countCollisions(string d) {
        //LR SR LS 
        //SL  RS  RL
        int n = d.size();
        int i=0; int j=n-1;
        while(i<n and d[i]=='L') i++;
        while(j>=0 and d[j]=='R') j--;
        
        int ans=0;
        for(int k=i;k<=j;k++){
            if(d[k]!='S') ans++;
        }
        return ans;
    }
};
Input: directions = "RLRSLL"
Output: 5
Explanation:
