// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity.
// Example 1:
// Input: [2,2,1]
// Output: 1
// Example 2:
// Input: [4,1,2,1,2]
// Output: 4

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> mySet;
        for(int i=0; i< nums.size(); i++){
            if(mySet.find(nums[i]) != mySet.end()){
                mySet.erase(nums[i]);
            }else{
                mySet.insert(nums[i]);
            }
        }
        set<int>::iterator it = mySet.begin();
        return *it;
    }
};
