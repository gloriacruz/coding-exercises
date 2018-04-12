
//This algorithm returns the Longest Increasing subsequence and its size with NlogN complexity

#include <vector>

using namespace std;

vector<int> longest_increasing_subsequence(vector<int> S) {
    cout<< "In ";
    int n = S.size();
    vector<int> M;
    M.push_back(0);
    vector<int> P;
    P.push_back(-1);
    int best_length = 1;

    for (int i=1; i<n; i++){
        cout<< "Processing: " << S[i] << " ";
        M.push_back(-1);
        P.push_back(-1);

        //cycle to go through M
        for(int j=best_length-1; j>=0; j--){
            if(S[i] > S[M[j]]){
                if(M[j+1] == -1){
                    best_length++;
                    //cout<< "Best Length: " << best_length << " ";
                }
                M[j+1]=i;
                //cout<< "Writing M[" << j+1 << "]=" << i << " ";
                P[i]=M[j];
                break;
            }
            else if(S[i] < S[M[j]] && j == 0){
                M[j]=i;
                //cout<< "Writing M[" << j << "]=" << i << " ";
            }
        }
    }

    vector<int> answer;
    int index = M[best_length-1];
    while (index != -1){
      answer.push_back(S[index]);
      index = P[index];
    }
    vector<int> answerReverse;
    for(int j=answer.size()-1; j>=0; j--){
        answerReverse.push_back(answer[j]);
    }

    return answerReverse;
}

int main(){
    int arr[] = {4,2,3,12,11};
    std::vector<int> sequence (arr, arr + sizeof(arr) / sizeof(int) );
    vector<int> temp = longest_increasing_subsequence(sequence);
    cout<< "LIS: " << temp << " with size: " << temp.size();

    return true;


}
