//This algorithm returns the Longest Increasing subsequence size with N^2 complexity

#include <vector>

using namespace std;

int longest_increasing_subsequence(vector<int> sequence) {

    vector<int> subSequence;
    vector<int> maxLengths;
    maxLengths.push_back(1);
    int bestLength = 1;
    int n=sequence.size();

    for(int i=1; i<n; i++){
        maxLengths.push_back(1);
        for(int j=0; j<i; j++){
        //cout<< " sequence[j]: " << sequence[j] << " sequence[i]: " << sequence[i] ;
            if(sequence[j] < sequence[i]){
                if(maxLengths[j]+1 > maxLengths[i])
                    maxLengths[i] = maxLengths[j]+1;
                if(maxLengths[i] > bestLength)
                    bestLength = maxLengths[i];
            }
        }
    }

    return bestLength;
}

int main(){

    int myints[] = {3,4,-1,0,6,2,3};
    std::vector<int> sequence (myints, myints + sizeof(myints) / sizeof(int) );
    int temp = longest_increasing_subsequence(sequence);
    cout<< "Length of LIS: " << temp << " ";

    return true;
}

