class SORTracker {
private:
    struct LtoS {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    struct StoL {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, LtoS> first;
    priority_queue<pair<int, string>, vector<pair<int, string>>, StoL> second;

public:
    SORTracker() {}

    void add(string name, int score) {
        pair<int, string> curr = {score, name};

        if (first.empty()) {
            second.push(curr);
            return;
        }

        auto topFirst = first.top();

        if (score > topFirst.first ||
            (score == topFirst.first && name < topFirst.second)) {

            first.pop();
            second.push(topFirst);
            first.push(curr);

        } else {
            second.push(curr);
        }
    }

    string get() {
        auto topSecond = second.top();
        second.pop();

        first.push(topSecond);

        return topSecond.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */