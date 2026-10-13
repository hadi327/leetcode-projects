
#include <bits/stdc++.h>
using namespace std;

class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> low, mid, high;
    long long sumMid = 0;

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
        } else if (high.empty() || x >= *high.begin()) {
            high.insert(x);
        } else {
            mid.insert(x);
            sumMid += x;
        }

        balance();
    }

    void remove(int x) {
        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
        } else if ((it = mid.find(x)) != mid.end()) {
            sumMid -= x;
            mid.erase(it);
        } else {
            it = high.find(x);
            high.erase(it);
        }

        balance();
    }

    void balance() {
        while ((int)low.size() > k) {
            auto it = prev(low.end());
            int x = *it;
            low.erase(it);
            mid.insert(x);
            sumMid += x;
        }

        while ((int)high.size() > k) {
            auto it = high.begin();
            int x = *it;
            high.erase(it);
            mid.insert(x);
            sumMid += x;
        }

        while ((int)low.size() < k && !mid.empty()) {
            auto it = mid.begin();
            int x = *it;
            mid.erase(it);
            sumMid -= x;
            low.insert(x);
        }

        while ((int)high.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            int x = *it;
            mid.erase(it);
            sumMid -= x;
            high.insert(x);
        }
    }

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        q.push(num);
        add(num);

        if ((int)q.size() > m) {
            int old = q.front();
            q.pop();
            remove(old);
        }
    }

    int calculateMKAverage() {
        if ((int)q.size() < m) {
            return -1;
        }

        return (int)(sumMid / (m - 2 * k));
    }
};
