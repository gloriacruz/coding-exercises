#include <iostream>
#include <vector>

using namespace std;

class Pos{
  public:
   int val;
   Pos(int x) : val(x) {};
};
enum Direction {Right, Down, Left, Up};

using Path = vector<Pos>;

// Given functions:
// bool isEnd(Pos p){}

// bool isBlocked(Pos p, Direction dir){}

// Pos move(Pos p, Direction dir){}

// int findPositionInPath(Path visited, Pos p){}

bool explorePosition(Pos start, Path & solution){
  solution.push_back(start);

  if(isEnd(start)){
    return true;
  }

  for(int i=0; i < Up; i++){
    Direction dir = (Direction) i;
    if(!isBlocked(start, dir)){
      Pos newPos = move(start, dir);
      if(findPositionInPath(solution, newPos) > -1){
        if(explorePosition(newPos, solution)){
          return true;
        }else{
          solution.pop_back();
        }
      }
    }
  }
  return false;
}

Path findPath(Pos start){
  Path solution;
  if(explorePosition(start, solution)){
    cout << "Found it!" << endl;
  }
  return solution;
}
