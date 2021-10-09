class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int max_after = values[n-1]-(n-1);
        int ans=INT_MIN;
        for(int i=n-2;i>=0;i--){
            max_after = max(max_after , values[i+1]-(i+1));
            ans = max(ans , max_after+values[i]+i);
        }
        return ans;
        
    }
};


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values){
        int n=values.size();
        int max_left=values[0]+0;
        int ans=INT_MIN;
        for(int j=1;j<n;j++){
            max_left = max(max_left , values[j-1]+j-1);
            ans = max(ans , max_left + values[j]-j);
        }
        return ans;
    }
};
