#include<iostream>
#include<vector>
using namespace std;

//Part of the N-queens question - given an N x N chess board with N queens already positioned on it, write a function to tell whether the queens are "safe" from each other or not.
//backtracking

//A queen is under attack if:
//1. There is another queen on the row
//2. There is another queen on the column
//3. There is another queen on the diagonal
//Tricks: Discover a diagonal
//If queen is in (1,2) 1-2=-1 \\\\ and 1+2=3 //// all other coordinates with those operations are under attack

//Start (0,0)
//For every row, try to place queen revise col by col for possible attack
//If no attack, place and move to the next row with recursion
//If attack, keep trying


class Position {
  public:
  int x;
  int y;
  //Position(int posx, int posy) : x(posx), y(posy) {}
  Position(int row, int col){
    this->x = row;
    this->y = col;
  }
};

vector<Position*> queens;

bool safe(Position* pos){
  for(auto queen : queens){
    if(queen->x == pos->x || queen->y == pos->y) return false;
    if(queen->x - queen->y == pos->x - pos->y) return false;
    if(queen->x + queen->y == pos->x + pos->y) return false;
  }
  return true;
}

bool placeQueenInRow(int x, int start, int n){
  for(int i=start; i<n; i++){
    Position* position = new Position(x,i);
    //cout << "tried " << position->x << "," << position->y << endl;
    if(safe(position)){
      queens.push_back(position);
      //cout << "pushed " << position->x << "," << position->y << endl;
      if(x+1 < n){
        if(placeQueenInRow(x+1, 0, n)){//place queen in row
          return true;
        }
      }
      else
        return true;//found 1 solution
    }
  }
  queens.pop_back();
  return false;//couldn't place queen in row
}

vector<vector<Position*>> solveNQueens(int n) {

  int start = 0;
  vector<vector<Position*>> solutions;

  while(placeQueenInRow(0, start, n)){
    solutions.push_back(queens);
    start = queens[0]->y + 1;
    queens.clear();
  }
  return solutions;
}


int main(){

  vector<vector<Position*>> solutions = solveNQueens(4);
  for(auto solution : solutions){
      cout << "Solution " << endl;
    for(auto queen : solution){
      cout << "Queen " << " (" << queen->x << "," << queen->y << ")" << endl;
    }
  }
  cout << "End";
  return 1;
}
