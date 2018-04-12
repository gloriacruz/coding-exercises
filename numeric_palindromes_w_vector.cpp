//This algorithm return true/false if a given number is a palindrome using a vector to break down the number

#include <cstdio>

int is_numeric_palindrome(long number) {

    int palindrome = true;
    if (number <= 0)
        return palindrome;

    int digit = 0;
    vector<int> list;

    while(number>0){
        digit = number%10;
        number = number/10;
        list.push_back(digit);
    }

    int count = list.size();
    int half = count/2;
    int i = 0;
    int j = count-1;

    while(i<=half && j>=half && palindrome == 1)
    {
         if(list[i] != list[j]){
            palindrome = false;
         }
         i++; j--;
    }

    return palindrome;
}

int main(){

    long number = 91233219;
    int tempPrint = is_numeric_palindrome(number);
    cout<< tempPrint << "";
}
