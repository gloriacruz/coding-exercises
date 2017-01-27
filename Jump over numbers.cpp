{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <vector>\
\
using namespace std;\
\
int jump_over_numbers(const vector<int>& list) \{\
    int P=0;\
    int N=list.size();\
    int jumpCounter=0;\
    do\{\
        if(list[P]>0)\
        \{\
            P=P+list[P];\
            jumpCounter++;\
        \}\
        else\
            return -1;\
    \}while(P<N);\
    \
    return jumpCounter;\
\}\
\
int main()\
\{\
    int myints[] = \{3,0,2,1\};\
    std::vector<int> list (myints, myints + sizeof(myints) / sizeof(int) );\
    int temp = jump_over_numbers(list);\
    cout<< temp <<" ";   \
    return 0;\
\}}