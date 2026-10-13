
#include <bits/stdc++.h>
using namespace std;

class StockPrice {
private:
    unordered_map<int, int> prices;
    multiset<int> allPrices;
    int latestTimestamp = 0;

public:
    StockPrice() {}

    void update(int timestamp, int price) {
        latestTimestamp = max(latestTimestamp, timestamp);

        // Remove the old price if this timestamp was updated
        if (prices.count(timestamp)) {
            auto it = allPrices.find(prices[timestamp]);
            allPrices.erase(it);
        }

        prices[timestamp] = price;
        allPrices.insert(price);
    }

    int current() {
        return prices[latestTimestamp];
    }

    int maximum() {
        return *allPrices.rbegin();
    }

    int minimum() {
        return *allPrices.begin();
    }
};
