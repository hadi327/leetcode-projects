#include <stdlib.h>
#include <stdbool.h>

#define SIZE 200003

typedef struct {
    int *values;
    int count;

    int *keys;
    int *indices;
    char *used;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = malloc(sizeof(RandomizedSet));

    obj->values = malloc(100000 * sizeof(int));
    obj->count = 0;

    obj->keys = malloc(SIZE * sizeof(int));
    obj->indices = malloc(SIZE * sizeof(int));
    obj->used = calloc(SIZE, sizeof(char));

    return obj;
}


int hash(int key) {
    long long x = key;

    if (x < 0)
        x = -x;

    return x % SIZE;
}


bool contains(RandomizedSet* obj, int val, int* position) {
    int h = hash(val);

    while (obj->used[h]) {
        if (obj->keys[h] == val) {
            *position = obj->indices[h];
            return true;
        }

        h = (h + 1) % SIZE;
    }

    return false;
}


bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int position;

    if (contains(obj, val, &position))
        return false;

    int h = hash(val);

    while (obj->used[h])
        h = (h + 1) % SIZE;

    obj->used[h] = 1;
    obj->keys[h] = val;
    obj->indices[h] = obj->count;

    obj->values[obj->count] = val;
    obj->count++;

    return true;
}


bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int position;

    if (!contains(obj, val, &position))
        return false;

    int lastIndex = obj->count - 1;
    int lastValue = obj->values[lastIndex];

    /*
     * Move the last element into the removed element's position.
     */
    obj->values[position] = lastValue;

    /*
     * Update the hash table for lastValue.
     */
    int h = hash(lastValue);

    while (obj->keys[h] != lastValue || !obj->used[h])
        h = (h + 1) % SIZE;

    obj->indices[h] = position;

    obj->count--;

    /*
     * Mark val as deleted.
     *
     * We can't simply clear the slot because
     * that would break linear probing.
     */
    h = hash(val);

    while (obj->keys[h] != val)
        h = (h + 1) % SIZE;

    obj->used[h] = 0;

    /*
     * Reinsert following elements in the cluster.
     */
    h = (h + 1) % SIZE;

    while (obj->used[h]) {
        int key = obj->keys[h];
        int index = obj->indices[h];

        obj->used[h] = 0;

        int newH = hash(key);

        while (obj->used[newH])
            newH = (newH + 1) % SIZE;

        obj->used[newH] = 1;
        obj->keys[newH] = key;
        obj->indices[newH] = index;

        h = (h + 1) % SIZE;
    }

    return true;
}


int randomizedSetGetRandom(RandomizedSet* obj) {
    int index = rand() % obj->count;

    return obj->values[index];
}


void randomizedSetFree(RandomizedSet* obj) {
    free(obj->values);
    free(obj->keys);
    free(obj->indices);
    free(obj->used);
    free(obj);
}