class LFUCache {
    struct Node {
        int key, value, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, list<Node*>> freqList;

    unordered_map<int, list<Node*>::iterator> position;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];

        updateFrequency(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->value = value;

            updateFrequency(node);

            return;
        }

        // Cache is full
        if (keyNode.size() == capacity) {

            auto& list = freqList[minFreq];

            Node* lfu = list.back();

            keyNode.erase(lfu->key);
            position.erase(lfu->key);

            list.pop_back();

            delete lfu;
        }

        // Insert new node
        Node* node = new Node(key, value);

        keyNode[key] = node;

        freqList[1].push_front(node);
        position[key] = freqList[1].begin();

        minFreq = 1;
    }

private:

    void updateFrequency(Node* node) {

        int oldFreq = node->freq;
        int key = node->key;

        // Remove from old frequency list
        freqList[oldFreq].erase(position[key]);

        // If this was the minimum frequency
        if (oldFreq == minFreq &&
            freqList[oldFreq].empty()) {

            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Add to new frequency list
        freqList[node->freq].push_front(node);

        position[key] = freqList[node->freq].begin();
    }
};