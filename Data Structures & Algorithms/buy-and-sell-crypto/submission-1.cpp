class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price= prices[0];
        int max_profit=0;
        for(int price : prices){
            if(price < min_price)
                min_price = price;
            else 
                max_profit = max(price-min_price , max_profit);
        }
        return max_profit;
    }
};
