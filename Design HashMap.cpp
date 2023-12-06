class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        data = vector<vector<pair<int, int>>>(g_hashSize);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int index = key % g_hashSize;

        auto keyIter = find_if(data[index].begin(), data[index].end(), [key](pair<int, int> iter) { return iter.first == key; });
        if (keyIter == data[index].end())
        {
            data[index].push_back(pair<int, int>(key, value));
        }
        else
        {
            *keyIter = pair<int, int>(key, value);
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = key % g_hashSize;

        auto keyIter = find_if(data[index].begin(), data[index].end(), [key](pair<int, int> iter) { return iter.first == key; });
        return keyIter == data[index].end() ? -1 : (*keyIter).second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = key % g_hashSize;

        auto keyIter = find_if(data[index].begin(), data[index].end(), [key](pair<int, int> iter) { return iter.first == key; });
        if (keyIter != data[index].end())
        {
            data[index].erase(keyIter);
        }
    }

private:
    const int g_hashSize = 1009; // it should be a prime, which could help us reducing conflicts
    vector<vector<pair<int, int>>> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */