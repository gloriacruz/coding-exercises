{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf760
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww21240\viewh11440\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <vector>\
#include <algorithm>\
\
using namespace std;\
\
vector< pair<int, int> > quickSort(const vector< pair<int, int> >& radars)\{\
    \
    int n = radars.size();\
\
    if(n <= 1)\
        return radars;    \
    int pivotIndex = n/2;\
    int pivot = radars[pivotIndex].first;\
    //cout << " Pivot: " << pivot << " " << endl;\
\
    vector< pair<int, int> > left;\
    vector< pair<int, int> > right;\
\
    for(int i=0; i<n; i++)\{\
        if(i != pivotIndex)\{\
            if(radars[i].first <= pivot)\{\
                left.push_back(radars[i]); //cout<<" Add to left: " << radars[i] << " ";\
            \}else\{\
                right.push_back(radars[i]); //cout<<" Add to right: " << radars[i] << " ";\
            \}\
        \}    \
    \}\
    \
    //cout<< " Try to concatenate " << endl;\
    vector< pair<int, int> > result;    \
    vector< pair<int, int> > resultRight;\
    result = quickSort(left);\
    //cout<< " Added left " << endl;\
    result.push_back(radars[pivotIndex]);\
    //cout<< " Added middle " << endl;\
    resultRight = quickSort(right);\
    int nRight = resultRight.size();\
    for(int j=0; j<nRight; j++)\{\
        result.push_back(resultRight[j]);\
    \}\
    //cout<< " Added right " << endl;\
\
    /*cout << " Result array: ";\
    for(int k=0; k<n; k++)\{\
        cout<< result[k] << endl;\
    \}*/\
\
    return result;\
\}\
\
int cover_the_border(int l, const vector< pair<int, int> >& radars) \{\
\
    if(l <= 0)\
        return 0;\
\
    int n = radars.size();\
\
    if(n <= 0)\
        return 0;\
\
    const vector< pair<int, int> > sortedRadars = quickSort(radars);\
\
    int radarArea = 0;\
    pair<int, int> currentStrip(0,0);\
\
    for(int i=0; i<n; i++)\{\
        if(sortedRadars[i].first <= currentStrip.second)\{\
            if(sortedRadars[i].second > currentStrip.second)\{\
                radarArea += sortedRadars[i].second - currentStrip.second;\
                currentStrip.second = sortedRadars[i].second;\
            \}\
        \}else\{\
            currentStrip.first = sortedRadars[i].first;\
            currentStrip.second = sortedRadars[i].second; \
            radarArea += sortedRadars[i].second - sortedRadars[i].first;  \
        \}\
        //cout<<" For " << i << " = " << radarArea << " currentStrip: " << currentStrip << endl;\
    \}\
    \
    return radarArea;\
\}\
\
int main()\{\
    \
    // Example arguments:\
    // l = 100\
    // radars = [ [5, 10], [3, 25], [46, 99], [39, 40], [45, 50] ]\
\
    int l= 100;\
    vector< pair<int, int> > radars;\
    radars.push_back(make_pair(5, 10));\
    radars.push_back(make_pair(3, 25));\
    radars.push_back(make_pair(46, 99));\
    radars.push_back(make_pair(39, 40));\
    radars.push_back(make_pair(45, 50));\
\
    int area = cover_the_border(l, radars);\
\
    cout << " Total area in m : " << area;\
\
    return 1;\
\}}