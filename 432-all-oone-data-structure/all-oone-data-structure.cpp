class AllOne {
public:
    struct Node {
        int count;
        unordered_set<string> keys;

        Node(int c) : count(c) {}
    };

    list<Node> buckets;
    unordered_map<string, list<Node>::iterator> pos;

    void inc(string key) {
        if (!pos.count(key)) {
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front(Node(1));
            }

            buckets.front().keys.insert(key);
            pos[key] = buckets.begin();
            return;
        }

        auto it = pos[key];
        int newCount = it->count + 1;

        auto next = std::next(it);

        if (next == buckets.end() ||
            next->count != newCount) {
            next = buckets.insert(
                next,
                Node(newCount)
            );
        }

        next->keys.insert(key);
        pos[key] = next;

        it->keys.erase(key);

        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    void dec(string key) {
        auto it = pos[key];

        if (it->count == 1) {
            it->keys.erase(key);
            pos.erase(key);

            if (it->keys.empty()) {
                buckets.erase(it);
            }

            return;
        }

        int newCount = it->count - 1;
        auto prev = (it == buckets.begin())
                    ? buckets.end()
                    : std::prev(it);

        if (it == buckets.begin() ||
            prev->count != newCount) {
            prev = buckets.insert(
                it,
                Node(newCount)
            );
        }

        prev->keys.insert(key);
        pos[key] = prev;

        it->keys.erase(key);

        if (it->keys.empty()) {
            buckets.erase(it);
        }
    }

    string getMaxKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.back().keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) {
            return "";
        }

        return *buckets.front().keys.begin();
    }
};