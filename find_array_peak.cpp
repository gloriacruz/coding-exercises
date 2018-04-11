
#include <iostream>
#include <vector>
using namespace std;

//O(n) complexity
// int findPeakElement(vector<int>& nums) {
//     int peakPos = 0;
//     int n = nums.size();

//     for(int i=1; i<n; i++){
//         if(nums[i] > nums[peakPos]){
//             peakPos = i;
//         }
//     }
//     return peakPos;
// }


//O(log(n)) complexity
int searchSpace(vector<int>& nums, int l, int r){
    if(l==r)
        return l;
    int mid = (l+r)/2;
    if(nums[mid] > nums[mid+1]){
        return searchSpace(nums, l, mid);
    }else{
        return searchSpace(nums, mid+1, r);
    }
}

int findPeakElement(vector<int>& nums){
    return searchSpace(nums, 0, nums.size()-1);
}


int main(){
    vector<int> v = {0, 2, 3, 6};
    cout << "in";
    cout <<"The peak is in index: " << findPeakElement(v);
    return 1;
}