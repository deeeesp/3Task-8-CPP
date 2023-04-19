#include "Pair.h"

#ifndef TASK3_MAP_H
#define TASK3_MAP_H

template<typename K, typename V>
class Map {
public:
    Map() {
        pairs = new Pair<K, V>[0];
    }

    ~Map() {
        delete[] pairs;
    }

public:

    int begin() { return 0; }

    int end() { return size; }

    Pair<K, V> insert(K key, V value) {
        return insert(Pair<K, V>(key, value));
    }

    Pair<K, V> insert(Pair<K, V> pair) {
        int ind = find(pair.getKey());
        if (ind != -1) {
            Pair<K, V> res(pairs[ind].getKey(), pairs[ind].getValue());
            pairs[ind].setValue(pair.getValue());
            return res;
        }
        pushBack(pair);
        return pair;


    }

    Pair<K, V> remove(K key) {
        int ind = find(key);
        Pair<K, V> pair(pairs[ind].getKey(), pairs[ind].getValue());
        if (ind != -1) {
            rebuildAfterRemove(ind);
        }
        return pair;
    }

    int find(K key) {
        for (int i = 0; i < size; ++i) {
            if (pairs[i].getKey() == key) {
                return i;
            }
        }
        return -1;
    }

    Pair<K, V> getByInd(int ind){
        return pairs[ind];
    }


private:
    void pushBack(K key, V value) {
        pushBack(Pair<K, V>(key, value));
    }

    void pushBack(Pair<K, V> value) {
        rebuildAfterAdd(end(), value);
    }

    int rewriteUntil(int ind, Pair<K, V> *rebuildValue) {
        int i;
        for (i = 0; i < size; ++i) {
            if (pairs[ind].getKey() == pairs[i].getKey()) {
                break;
            }
            rebuildValue[i] = Pair<K, V>(pairs[i].getKey(), pairs[i].getValue());
        }
        return i;
    }

    void rebuildAfterAdd(int ind, Pair<K, V> &value) {
        Pair<K, V> *rebuildValue = new Pair<K, V>[size + 1];
        int i = rewriteUntil(ind, rebuildValue);
        rebuildValue[i] = value;
        delete[] pairs;
        pairs = rebuildValue;
        size++;
    }

    void rebuildAfterRemove(int ind) {
        Pair<K, V> *rebuildValue = new Pair<K, V>[size - 1];
        int i = rewriteUntil(ind, rebuildValue) + 1;
        for (i; i < size; ++i) {
            rebuildValue[i - 1] = Pair<K, V>(pairs[i].getKey(), pairs[i].getValue());
        }
        delete[] pairs;
        pairs = rebuildValue;
        size--;
    }

private:
    Pair<K, V> *pairs;
    int size = 0;
};


#endif //TASK3_MAP_H
