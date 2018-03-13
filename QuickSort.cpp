#include <vector>
#include <iostream>
using namespace std;

vector<int> concatenate(vector<int> arr1, vector<int> arr2, vector<int> arr3){
    std::vector<int> result;
    result.reserve(arr1.size() + arr2.size() + arr3.size());
    result.insert(result.end(), arr1.begin(), arr1.end());
    result.insert(result.end(), arr2.begin(), arr2.end());
    result.insert(result.end(), arr3.begin(), arr3.end());
    return result;
}

vector<int> quicksort(vector<int> data){

    int n = data.size();
    if(n <= 1)
        return data;

    int pivotIndex = n/2;
    int pivot = data[pivotIndex];
    int arrPivot[] = {pivot};
    std::vector<int> vPivot(arrPivot, arrPivot + sizeof(arrPivot)/sizeof(int));

    vector<int> left;
    vector<int> right;

    for(int i=0; i<n; i++){
        if(i != pivotIndex){
            if(data[i] <= pivot){
                left.push_back(data[i]);
            }else{
                right.push_back(data[i]);
            }
        }
    }

    return concatenate(quicksort(left),vPivot,quicksort(right));
}

int main(){
    int arr[] = {3,7,8,5,2,4};
    std::vector<int> input(arr, arr + sizeof(arr)/sizeof(int));
    // std::vector<int> input = {3,7,8,5,2,4};
    vector<int> result = quicksort(input);

    //Print result
    int n = result.size();
    cout << " Final result array: ";
    for(int i=0; i<n; i++){
        cout<< result[i] << " ";
    }

    return 1;
}
