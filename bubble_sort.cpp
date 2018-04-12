#include <iostream>
#include <vector>

using namespace std;

// void Swap(vector<int> &data, int pos1, int pos2){
//   int temp = data[pos1];
//   data[pos1] = data[pos2];
//   data[pos2] = temp;
//   return;
// }

void Swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
  return;
}

void PrintArray(vector<int> array){
  int n = array.size();
  cout << "Array: ";
  for(int i=0; i<n; i++){
    cout<< array[i] << " ";
  }
}

vector<int> BubbleSort(vector<int> data){

  int n = data.size();
  bool swapped;

  do{
    swapped = false;
    for(int i=0; i<n-1; i++){
      if(data[i]>data[i+1]){
        //Swap(data,i,i+1);
        Swap(data[i],data[i+1]);
        swapped = true;
      }
    }
    //Optimization: the last number is always sorted after a full pass
    n = n - 1;
  }while(swapped != false);

  return data;
}

int main(){
  std::vector<int> input = {3,7,8,5,2,4};
  vector<int> result = BubbleSort(input);

  //Print result
  PrintArray(result);

  return 1;
}

