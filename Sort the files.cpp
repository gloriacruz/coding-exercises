{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf760
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww18400\viewh14420\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 //Sort the files problem by generating the files (no sorting)\
\
#include <vector>\
#include <string>\
#include <sstream>\
\
using namespace std;\
\
\
void generate_the_files(int n, int level, int fileNum, vector<string>& result) \{\
\
    if(fileNum > n || result.size() > 1000) \
        return;\
\
    if(level > 0) // Don't write IMG0.jpg\
    \{\
        ostringstream sFileNum;\
        sFileNum << fileNum;      \
        result.push_back("IMG"+sFileNum.str()+".jpg");\
    \}\
\
    for(int i=0; i<=9; i++)\{\
        if(i != 0 || level != 0) // Skips when i=0 & level=0. Starts with IMG1.jpg instead of looping with 0\
        generate_the_files(n, level+1, fileNum*10+i, result); \
    \}         \
\
\}\
\
void sort_the_files(int n, vector<string>& result)\{\
    \
    generate_the_files(n, 0, 0, result);\
\}\
\
\
int main()\{\
\
    vector<string> result;\
    int n =100;\
\
    sort_the_files(n, result);\
\
    n = result.size();\
    cout << " Final result array: ";\
    for(int i=0; i<n; i++)\{\
        cout<< result[i] << endl;\
    \}\
\
    return 1;\
\}\
\
\
}