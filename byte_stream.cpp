//A byte stream consists of 2-byte and 3-byte words, each byte is either 0 or 1, so like "001 01 10 100 ..."
//Given an arbitrary position in the stream (including in the middle of a word), come up with a solution to decode the stream.
//"001 01 10 100" = 1126

#include <iostream>
#include <unordered_map>
#include <ctype.h>
using namespace std;

unordered_map<string, string> hashDecode {
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

string decodeStream(string bytestream){

  string solution;
  string word;
  for(char ch : bytestream ) {
      if(ch == " "){
          word += ch;
      }else{
          cout << word << endl;
          solution += hashDecode[word];
          word = "";
      }
  }
  return solution;
}


int main(){
  cout << decodeStream("001 01 10 100");
  return 1;
}
