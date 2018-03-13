#include <vector>

using namespace std;

int jump_over_numbers(const vector<int>& list) {
    int P=0;
    int N=list.size();
    int jumpCounter=0;
    do{
        if(list[P]>0)
        {
            P=P+list[P];
            jumpCounter++;
        }
        else
            return -1;
    }while(P<N);

    return jumpCounter;
}

int main()
{
    int myints[] = {3,0,2,1};
    std::vector<int> list (myints, myints + sizeof(myints) / sizeof(int) );
    int temp = jump_over_numbers(list);
    cout<< temp <<" ";
    return 0;
}
