// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity.
// Example 1:
// Input: [2,2,1]
// Output: 1
// Example 2:
// Input: [4,1,2,1,2]
// Output: 4
//SOLUTION BIT MANIPULATION
// Concept
// If we take XOR of zero and some bit, it will return that bit
// a XOR 0 = a
// If we take XOR of two same bits, it will return 0
// a XOR a = 0
// a XOR b XOR a = (a XOR a) XOR b = 0 XOR b = b
// So we can XOR all bits together to find the unique number.

using namespace std;

class Solution {
public:
    // a XOR 0 = a
    // a XOR a = 0
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = result ^ nums[i];
        }
        return result;
    }

};


