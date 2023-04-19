#ifndef TASK3_PAIR_H
#define TASK3_PAIR_H

template<typename K, typename V>
class Pair
{
public:
    Pair() {}

    Pair(K key, V value)
    {
        this->key = key;
        this->value = value;
    }

public:
    K& getKey()
    {
        return key;
    }
    void setKey(K key)
    {
        this->key = key;
    }

    V& getValue()
    {
        return value;
    }
    void setValue(V value)
    {
        this->value = value;
    }

private:
    K key;
    V value;
};

#endif //TASK3_PAIR_H
