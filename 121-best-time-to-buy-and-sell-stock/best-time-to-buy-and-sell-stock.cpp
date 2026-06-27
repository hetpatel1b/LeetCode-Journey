class Solution {
public:
   int maxProfit(vector<int>& prices) {
        // Initialize the buying price with the first day's price
       int buy = prices[0];
       int profit = 0;


       // Traverse the array from the second day to the last day
       for (int i = 1; i < prices.size(); i++) {
           // If we find a lower price, update the buy value
           if (prices[i] < buy) {
               buy = prices[i];
           }
           // If selling today gives a better profit, update the profit
           else if (prices[i] - buy > profit) {
               profit = prices[i] - buy;
           }
       }


       // Return the maximum profit found
       return profit;
   }
};
