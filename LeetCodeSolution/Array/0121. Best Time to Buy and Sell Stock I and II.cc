
// 121. Best Time to Buy and Sell Stock 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int curr = 0; int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] - min_price > max_profit)
                max_profit = prices[i]-min_price;
            if(prices[i] < min_price) 
                min_price = prices[i];
        }
        return max_profit;
    }
};

// similar
class Solution2{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};


// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=1;i<n;i++){
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};
