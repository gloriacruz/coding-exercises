#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
protected:
    list<int> ranking; //key ranking by use
    unordered_map<int, pair<int, list<int>::iterator>> hash_table;
    int _capacity;

public:

    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
      if(hash_table.find(key) != hash_table.end()){
          ranking.erase(hash_table[key].second);
          ranking.push_back(key);
          return hash_table[key].first;
      }else{
          return -1;
      }
    }

    void put(int key, int value) {

      if(hash_table.find(key) != hash_table.end()){
        ranking.erase(hash_table[key].second);
      }else if(hash_table.size() == _capacity){
        hash_table.erase(ranking.front());
        ranking.pop_front();
      }
      ranking.push_back(key);
      hash_table[key] = {value, --ranking.end()}; //update or insert
    }
};

int main(){
  //Your LRUCache object will be instantiated and called as such:
  LRUCache *cache = new LRUCache(2);
  cout << "start" << endl;
  cache->put(1, 1);
  cache->put(2,2);
  cout << cache->get(1)<< endl;       // returns 1
  cache->put(3, 3);                   // evicts key 2
  cout << cache->get(2)<< endl;       // returns -1 (not found)
  cache->put(4, 4);                   // evicts key 1
  cout << cache->get(1)<< endl;       // returns -1 (not found)
  cout << cache->get(3)<< endl;       // returns 3
  cout << cache->get(4)<< endl;       // returns 4
}
