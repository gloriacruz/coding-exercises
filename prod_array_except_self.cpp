// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].
//Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> left(n,1);
      vector<int> output(n,1);

      for(int i=1; i<n; i++){
        left[i] = (nums[i-1]*left[i-1]);
      }

      // Solution with O(2n) and 1 array O(n)
      int right = 1;
      for(int j=n-1; j>=0; j--){
        output[j] = left[j] * right;
        right = right * nums[j];
      }

      // Solution with O(3n) and 2 arrays O(2n)
      // vector<int> right(n,1);
      // for(int j=n-2; j>=0; j--){
      //   right[j] = (nums[j+1]*right[j+1]);
      // }

      // for(int k=0; k<n; k++){
      //   output[k] = left[k] * right[k];
      // }

      return output;
    }
};

int main(){
  vector<int> nums = {5,6,2,2};
  Solution *sol = new Solution;
  vector<int> output = sol->productExceptSelf(nums);

  for(int i=0; i<output.size(); i++){
    cout << output[i] << " ";
  }
}

