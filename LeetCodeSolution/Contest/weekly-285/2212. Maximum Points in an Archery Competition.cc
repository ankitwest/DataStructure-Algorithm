class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans;
        int score = 0;
        for(int i=1;i<=1<<12;i++){
            int arrows = numArrows;
            vector<int> temp(12,0);
            for(int j=11;j>=0;j--){
                if(i&(1<<j)){
                    if(arrows<=aliceArrows[j])
                        continue;
                    arrows -= (aliceArrows[j]+1);
                    temp[j] = aliceArrows[j]+1;
                }
            }
            
            for(int j=0;j<12;j++){
                if(i&(1<<j)){
                    temp[j] += arrows;
                    break;
                }
            }
            int b=0;
            for(int j=0;j<12;j++){
                if(temp[j]>aliceArrows[j]) b+=j;
            }
            if(b>score) score=b,ans=temp;
        }
         return ans;
    }
};

