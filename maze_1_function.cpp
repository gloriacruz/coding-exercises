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

// Path concatenatePaths(Path left, Path right){}

//int findPositionInPath(Path visited, Pos p){}

Path visited;

Path findPath(Pos start, Path & visited){
  Path noPath;
  visited.push_back(start);

  if(isEnd(start)){
    return visited;
  }

  for(int i=0; i < Up; i++){
    Direction dir = (Direction) i;
    if(!isBlocked(start, dir)){
      Pos newPos = move(start, dir);
      if(findPositionInPath(visited, newPos) > -1){
        Path subSolution = findPath(newPos, visited);
        if(subSolution.size() > 0){
          return concatenatePaths(visited, subSolution);
        }
      }
    }
  }
  return noPath;
}

