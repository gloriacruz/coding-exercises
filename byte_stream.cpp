//A byte stream consists of 2-byte and 3-byte words, each byte is either 0 or 1, so like "001 01 10 100 ..."
//Given an arbitrary position in the stream (including in the middle of a word), come up with a solution to decode the stream.

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  unordered_map<char[3],char[1]> hash = {
    {"00","0"},
    {"01","1"},
    {"10","2"},
    {"11","3"},
    {"000","0"},
    {"001","1"},
    {"010","2"},
    {"011","3"},
    {"100","6"},
    {"110","8"},
    {"111","9"}
  };



};
