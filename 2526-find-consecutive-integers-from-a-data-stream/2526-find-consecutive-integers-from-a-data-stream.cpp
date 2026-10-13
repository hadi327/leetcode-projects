
#include <bits/stdc++.h>
using namespace std;

class DataStream {
private:
    int value;
    int k;
    int consecutive;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        consecutive = 0;
    }

    bool consec(int num) {
        if (num == value) {
            consecutive++;
        } else {
            consecutive = 0;
        }

        return consecutive >= k;
    }
};
