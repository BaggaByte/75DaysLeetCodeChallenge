int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        // If we found a new lower price, update min_price
        if (prices[i] < min_price) {
            min_price = prices[i];
        } 
        // Otherwise, see if selling today gives us a better profit
        else {
            int current_profit = prices[i] - min_price;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
    }

    return max_profit;
}