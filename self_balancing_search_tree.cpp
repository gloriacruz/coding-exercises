//Leetcode
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

// Example 1:
// Input: [1,2,3,1], k = 4, t = 0
// Output: true
// Example 2:
// Input: [1,0,1,1], k = 1, t = 0
// Output: true
// Example 3:
// Input: [4,2], k = 2, t = 1
// Output: false

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> sbbst;

    //if(nums.empty()) return false;
    //if(nums.size() == 1) return false;

    for(int i = 0; i < nums.size(); i++){
        //1st condition
        //right side
        set<int>::iterator itRight = sbbst.upper_bound(nums[i]);
        cout << "right: " << *itRight;
        if(itRight != sbbst.end() && (*itRight <= t + nums[i])) return true;

        //left side
        set<int>::iterator itLeft = sbbst.lower_bound(nums[i]);
        cout << "left: " << *itLeft;
        if(itLeft != sbbst.end() && (nums[i] <= t + *itLeft)) return true;

        sbbst.insert(nums[1]);
        //2 condition => |i-j|<=k
        if(sbbst.size() > k)
            sbbst.erase(nums[i-k]);
    }
    return false;
}
