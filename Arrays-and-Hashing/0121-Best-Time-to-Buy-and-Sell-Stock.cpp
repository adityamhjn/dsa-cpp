/*
 * Problem: 121. Best Time to Buy and Sell Stock
 * * Time Complexity: O(N) - We scan through the prices exactly once.
 * Space Complexity: O(1) - We only track two variables (minPrice and maxProfit).
 * * Intuition: 
 * We use a dynamic tracking approach (a simplified Sliding Window).
 * We do not need to check every pair. We only need to know the lowest price 
 * we have seen *so far*, and calculate the potential profit if we sold today.
 * We continuously update the global maximum profit.
 */

#include <vector>
#include <algorithm> // Required for std::max and std::min

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Defensive programming: guard against empty inputs
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // Calculate potential profit today before updating minPrice
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
            
            // Update the lowest price seen so far
            minPrice = std::min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};