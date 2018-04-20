#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> quickSort(const vector<int>& task_difficulties){

    int n = task_difficulties.size();

    if(n <= 1)
        return task_difficulties;
    int pivotIndex = n/2;
    int pivot = task_difficulties[pivotIndex];
    //cout << " Pivot: " << pivot << " " << endl;

    vector<int> left;
    vector<int> right;

    for(int i=0; i<n; i++){
        if(i != pivotIndex){
            if(task_difficulties[i] <= pivot){
                left.push_back(task_difficulties[i]); //cout<<" Add to left: " << task_difficulties[i] << " ";
            }else{
                right.push_back(task_difficulties[i]); //cout<<" Add to right: " << task_difficulties[i] << " ";
            }
        }
    }

    //cout<< " Try to concatenate " << endl;
    vector<int> result;
    vector<int> resultRight;
    result = quickSort(left);
    //cout<< " Added left " << endl;
    result.push_back(pivot);
    //cout<< " Added middle " << endl;
    resultRight = quickSort(right);
    int nRight = resultRight.size();
    for(int j=0; j<nRight; j++){
        result.push_back(resultRight[j]);
    }
    //cout<< " Added right " << endl;

    /*cout << " Result array: ";
    for(int k=0; k<n; k++){
        cout<< result[k] << endl;
    }*/

    return result;
}

int maximum_completed_tasks(int n, int t, const vector<int>& task_difficulties) {

    if(n <= 0)
        return 0;

    vector<int> sortedTasks = quickSort(task_difficulties);

    int totalTasks = 0;
    int accumulated = 0;

    for(int i=0; i<n; i++){
        accumulated += sortedTasks[i];
        if(i > 0)
            accumulated += abs(sortedTasks[i-1] - sortedTasks[i]);
        if(accumulated <= t){
            totalTasks++; //cout<<" Total with i=" << i << " is: "<< totalTasks << ", Accum: " << accumulated;
        }else{
            break;
        }
    }

    return totalTasks;
}

int main(){

    int n = 5;
    int t = 65;
    int arr[] = {24,23,22,10,20};
    vector<int> task_difficulties (arr, arr+sizeof(arr)/sizeof(int));

    int maxTaks = maximum_completed_tasks(task_difficulties.size(), t, task_difficulties);

    cout << " Max Tasks: " << maxTaks;

    return 1;
}
