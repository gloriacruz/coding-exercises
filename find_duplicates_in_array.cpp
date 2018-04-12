#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> findDuplicates(vector<int>& nums) {
  unordered_map<int, int> map;
  for(int i=0; i<nums.size(); i++){
    if(map.find(nums[i]) == map.end()){
        map.insert(make_pair(nums[i],1));
    }else{
        map[nums[i]] = map[nums[i]] + 1;//map[nums[i]]++?
    }
  }
  vector<int> res;
  for(auto kvpair : map ){
    if(kvpair.second > 1){
        res.push_back(kvpair.first);
    }
  }
  return res;
}

int main(){
  vector<int> v = {4,3,2,7,8,2,3,1};
  vector<int> res =findDuplicates(v);

  for(int num : res) cout << num << ",";

  return 1;
}
