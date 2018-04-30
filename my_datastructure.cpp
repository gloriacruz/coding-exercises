// Design a data structure that supports all following operations in average O(1) time.

// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
      hash_table.clear();
      values.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_table.find(val) != hash_table.end()){
            return false;
        }else{
            int size = hash_table.size();
            hash_table[val] = size;
            values.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash_table.find(val) != hash_table.end()){
            int index = hash_table[val];
            hash_table.erase(val);
            values.erase(values.begin()+index);//maybe not constant
            return true;
        }else{
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int randomNum = rand();
        //cout << "random num " << randomNum << endl;
        int randInt = randomNum % values.size();
        //cout << "size " << values.size() << endl;
        //cout << "random " << randInt << endl;
        return values[randInt];
    }

private:
    unordered_map<int, int> hash_table;
    vector<int> values;
};


int main() {
 RandomizedSet *obj = new RandomizedSet();
 cout << obj->insert(-2) << endl;
 cout << obj->insert(-3) << endl;
 cout << obj->insert(-4) << endl;
 cout << obj->insert(4) << endl;
 cout << obj->remove(-3) << endl;
 cout << obj->remove(3) << endl;
 cout << obj->getRandom();
return 1;
}
