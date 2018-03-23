//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1
// 123 -> "One Hundred Twenty Three"
// 12 345 -> "Twelve Thousand Three Hundred Forty Five"
// 1 234 567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 2 147 483 647 -> "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven"

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
  string words[28] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
  string multipliers[4] = {"Hundred","Thousand","Million","Billion"};

  string subNumberToWords(int num){ ///max:999, min:1
    string english = "";

    int div = num/100;
    int rest = num%100;
    if(div >= 1) english += words[div] + " " + multipliers[0] + " " ;
    num = rest;

    if(num >= 0 && num <= 20){
     english += words[num];
    }else{
      div = num/10;
      rest = num%10;
      english += words[div+18] + " " + words[rest];
    }

    return english;
  }

  string numberToWords(int num){

    if(num == 0) return "Zero";

    string english = "";

    int div =  num/1000000000;
    int rest = num%1000000000;
    if(div >= 1) english += words[div] + " " + multipliers[3] + " " ;
    num = rest;

    div =  num/1000000;
    rest = num%1000000;
    if(div >= 1) english += subNumberToWords(div) + " " + multipliers[2] + " " ;
    num = rest;

    div =  num/1000;
    rest = num%1000;
    if(div >= 1) english += subNumberToWords(div) + " " + multipliers[1] + " " ;
    num = rest;

    if(num >= 1) english += subNumberToWords(num);

    return english;
  }
};

int main(){
  Solution *sol = new Solution;

  int num = 0;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 100;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 1567;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 123;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 12345;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 1234567;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;
  num = 2147483647;
  cout << "English of " << num << " " << sol->numberToWords(num) << endl;

  return 1;
}
