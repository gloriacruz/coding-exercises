// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
protected:
    int maxRank = 0;

    unordered_map<int, vector<int>> hash_table;

    int getLRU(){
        int minRank = 0;
        int minRankKey = 0;
        for(auto it : hash_table){
            if(minRank == 0){
                minRank = it.second[1];
                minRankKey = it.first;
            }else{
                if(minRank > (it.second)[1]){
                    minRank = (it.second)[1];
                    minRankKey = it.first;
                }
            }
        }
        return minRankKey;
    }

public:
    int capacity_;

    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if(hash_table.count(key) > 0){
            maxRank++;
            hash_table[key][1] = maxRank;
            return hash_table[key][0];
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        maxRank++;
        vector<int> values;
        values.push_back(value);
        values.push_back(maxRank);

        if(hash_table.size() == capacity_ && hash_table.count(key) == 0){
          int minRankKey = getLRU();
          hash_table.erase(minRankKey);
        }
        hash_table[key] = values; //update or insert
    }
};

int main(){
  //Your LRUCache object will be instantiated and called as such:
  LRUCache *cache = new LRUCache(2);
  cout << "start" << endl;
  (*cache).put(1, 1);
  cache->put(2,2);
  cout << cache->get(1)<< endl;       // returns 1
  cache->put(3, 3);                   // evicts key 2
  cout << cache->get(2)<< endl;       // returns -1 (not found)
  cache->put(4, 4);                   // evicts key 1
  cout << cache->get(1)<< endl;       // returns -1 (not found)
  cout << cache->get(3)<< endl;       // returns 3
  cout << cache->get(4)<< endl;       // returns 4
}
