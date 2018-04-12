
//This algorithm return true/false if a given number is a palindrome

#include <cstdio>

int is_numeric_palindrome(long number) {

    int palindrome = true;
    if (number <= 0)
        return palindrome;

    int digit = 0;
    int arr[11];
    int x = 0;

    while(number>0){
        digit = number%10;
        number = number/10;
        arr[x]=digit;
        x++;
    }

    int count = x;
    int half = count/2;
    int i = 0;
    int j = count-1;

    while(i<=half && j>=half && palindrome == 1)
    {
         if(arr[i] != arr[j]){
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

