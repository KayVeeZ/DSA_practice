#include<stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;

    int minPrice = prices[0]; // initialise minprice to first day
    int maxProfit = 0; // on first day if you sell profit is 0

    for (int i = 1; i < pricesSize; i++)
    {
        // if sell the next day price is greater than previous profit, then update it
        if ((prices[i] - minPrice) > maxProfit) 
        {
            maxProfit = prices[i] - minPrice;
        }

        // if today's price is lesser than minPrice than update it
        if (prices[i] < minPrice) 
        {
            minPrice = prices[i]; 
        }
    }
    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    // int prices[] = {7, 6, 4, 3, 1};
    // int prices[] = {2, 4, 1};


    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int profit = maxProfit(prices, pricesSize);
    printf("Maximum profit: %d\n", profit);
    return 0;
}