class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        int minPrice = prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
                profit = max(profit,prices[i]-minPrice);
            else
                minPrice = min(minPrice , prices[i]);
        }
        return profit;
    }
};



class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};
