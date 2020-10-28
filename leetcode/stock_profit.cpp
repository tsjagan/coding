#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "timer.h"
#include "utils.h"

using namespace std;


/*
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made from buying and selling that stock.
You're also given a number fee that represents a transaction fee for each buy and sell transaction.

You must buy before you can sell the stock, but you can make as many transactions as you like.

For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9,
since you could buy the stock at 1 dollar, and sell at 8 dollars, and then buy it at 4 dollars and sell it at 10 dollars. Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.

*/

int max_profit(vector<int>&& prices, int fees) {
  // 2 choices on each day:
  // either buy -> prev_sell_val + fees - prices[i];
  // or sell -> prev_buy_val + fees + prices[i];
  int hold = -(prices[0]);
  int sell = 0;

  for (int i = 1; i < prices.size(); i++) {
    int hold_prev = hold;
    hold = max(hold_prev, (sell - prices[i]));
    sell = max(sell, (hold_prev - fees) + prices[i]);
    cout << "hold/sell at " << i << " is " << hold << "/" << sell << endl;
  }
  return sell;
}

int main(void) {
  auto arr = {1, 3, 2, 8, 4, 10};
  int fees = 2;

  cout << max_profit(arr, fees) << endl;
  return 0;
}