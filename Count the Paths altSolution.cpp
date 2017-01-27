{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf760
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 //Solution 2\
\
\
#include <vector>\
#include <string>\
\
using namespace std;\
\
const int MAX_ROWS = 512;\
const int MAX_COLS = 512;\
\
int count_the_paths(vector<string> grid) \{\
\
    int counter = 0;\
    int N = grid.size();//rows\
    if(N <= 0)\
        return 0;\
\
    int M = grid[0].length();//cols\
    if(M <= 0)\
        return 0;\
\
    if(N == 1 && M == 1)\
        return 1;//single cell in grid\
    if((N == 1 && M == 2) || (N == 2 && M == 1))\
        return 1;//two cells in grid (end and start)\
\
    int m[MAX_ROWS][MAX_COLS];//matrix for pathsCount\
\
    for(int i=0;i<N;i++)\{\
        for(int j=0;j<M;j++)\{\
            if(i == 0 || j == M-1) //first row\
                m[i][j]=1;\
            else\
                m[i][j]=-1;\
        \}\
    \}\
\
    m[N-1][0] = 0; //start\
    m[0][M-1] = 0; //end\
\
    for(int x=0;x<N;x++)\{\
        for(int y=0;y<M;y++)\{\
            if(grid[x].at(y) == '1') //first row\
                m[x][y] = 0;\
        \}\
    \}\
   \
    for(int a=M-2;a>=0;a--)\{\
        for(int b=1;b<N;b++)\{\
            if(m[b][a] < 0)\
                m[b][a] = (m[b-1][a] + m[b][a+1]) % 1000003;         \
                \
        \}\
    \}\
     \
    for(int ii=0;ii<N;ii++)\{\
        for(int jj=0;jj<M;jj++)\{\
            cout<<" "<< m[ii][jj] <<" ";\
        \}\
        cout<< endl;\
    \}\
\
    return (m[N-2][0]+m[N-1][1]) % 1000003; \
\}\
\
int main()\{\
\
    string str1 = "0000";\
    string str2 = "0000";\
    string str3 = "0000";\
    string str4 = "0000";\
    //string str5 = "";\
\
    /*for(int i=0;i<4;i++)\{\
        str1.append("0");\
        str2.append("0");\
        str3.append("0");\
        str4.append("0");\
        //str5.append("0");\
    \}*/\
    string arr[] = \{str1,str2,str3,str4\};\
\
    std::vector<string> grid (arr, arr + sizeof(arr) / sizeof(string) );\
\
    /*vector<string> grid;\
    for(int i=0;i<512;i++)\{\
        for(int j=0;j<512;j++)\{\
            str1.append("0");\
        \}\
        grid.push_back(str1);\
    \}*/\
\
    int temp = count_the_paths(grid);\
    cout<< "No. of possible paths: " << temp ;\
\
    return true;\
\}}