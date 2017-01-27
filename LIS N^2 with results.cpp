{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf760
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww13380\viewh12200\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 //This algorithm returns the Longest Increasing subsequence and its size with N^2 complexity\
\
#include <vector>\
\
using namespace std;\
\
vector<int> longest_increasing_subsequence(vector<int> sequence) \{\
    \
    int bestLength = 1;\
    int n=sequence.size();\
    vector<int> subSequence;\
    vector<int> maxLengths; //stores LIS length up to a point in the sequence\
    maxLengths.push_back(1);\
\
    vector< vector<int> > LIS(n); //stores LIS up to a point in the sequence\
    LIS[0].push_back(sequence[0]);\
    subSequence.push_back(sequence[n-1]); //stores the LIS (LAST one found in case of a tie)\
  \
    for(int i=1; i<n; i++)\{    \
        //cout<< " first for ";\
        maxLengths.push_back(1);\
        LIS[i].push_back(sequence[i]);\
        for(int j=0; j<i; j++)\{    \
            //cout<< " sequence[j]: " << sequence[j] << " sequence[i]: " << sequence[i] ;\
            \
            if(sequence[j] < sequence[i])\{\
                if(maxLengths[j]+1 >= maxLengths[i])\{\
                    maxLengths[i] = maxLengths[j] + 1;\
                    LIS[i].clear(); \
                    LIS[i] = LIS[j]; \
                    LIS[i].push_back(sequence[i]);                \
                \}\
\
                if(maxLengths[i] >= bestLength)\{\
                    bestLength = maxLengths[i];\
                    subSequence.clear();\
                    subSequence = LIS[i];\
                \}\
            \}\
        \}\
    \}\
\
    return subSequence; //In case of a tie, returns the LAST LIS found\
\}\
\
int main()\{\
\
    int arr[] = \{1,2,3,4,0,0,2\};\
    std::vector<int> sequence (arr, arr + sizeof(arr) / sizeof(int) );\
    vector<int> temp = longest_increasing_subsequence(sequence);\
    cout<< "LIS: " << temp << " with size: " << temp.size();\
\
    return true;\
\}}