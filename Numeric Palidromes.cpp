{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf760
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww19820\viewh15560\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 //This algorithm return true/false if a given number is a palindrome \
\
#include <cstdio>\
\
int is_numeric_palindrome(long number) \{\
    \
    int palindrome = true;\
    if (number <= 0)\
        return palindrome;\
    \
    int digit = 0;\
    int arr[11];\
    int x = 0;\
    \
    while(number>0)\{\
        digit = number%10;\
        number = number/10;\
        arr[x]=digit;\
        x++;\
    \}\
    \
    int count = x;\
    int half = count/2;\
    int i = 0;\
    int j = count-1;\
    \
    while(i<=half && j>=half && palindrome == 1)\
    \{\
         if(arr[i] != arr[j])\{\
            palindrome = false;\
         \}\
         i++; j--;\
    \}\
    \
    return palindrome;\
\}\
\
int main()\{\
\
    long number = 91233219;\
    int tempPrint = is_numeric_palindrome(number);\
    cout<< tempPrint << "";\
\}\
\
}