
#include <bits/stdc++.h>
using namespace std;

class RideSharingSystem {
private:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> activeRiders;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
        activeRiders.insert(riderId);
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // Skip cancelled riders
        while (!riders.empty() &&
               activeRiders.find(riders.front()) == activeRiders.end()) {
            riders.pop();
        }

        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }

        int driverId = drivers.front();
        drivers.pop();

        int riderId = riders.front();
        riders.pop();

        activeRiders.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        activeRiders.erase(riderId);
    }
};
