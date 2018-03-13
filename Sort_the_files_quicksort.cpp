//Sort the files problem by generating the files and actually sorting them with Quicksort

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> quickSort(vector<string> files){

    int n = files.size();
    //cout << " Entro quicksort w file size: " << n << endl;

    if(n <= 1)
        return files;

    int pivotIndex = files.size()/2;
    string pivot = files[pivotIndex];
    //cout << " Pivot: " << pivot << " " << endl;

    vector<string> left;
    vector<string> right;

    for(int i=0; i<n; i++){
        if(i != pivotIndex){
            if(files[i] <= pivot){
                left.push_back(files[i]); //cout<<" Add to left: " << files[i] << " ";
            }else{
                right.push_back(files[i]); //cout<<" Add to right: " << files[i] << " ";
            }
        }
    }

    //cout<< " Try to concatenate " << endl;
    vector<string> result;
    vector<string> resultRight;
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

void sort_the_files(int n, vector<string>& result) {

    vector<string> files;
    string temp;

    for(int i=1; i<=n; i++){
        ostringstream convert;
        convert << i;
        temp = "IMG" + convert.str() + “.jpg”;
        files.push_back(temp);
    }

    result = quickSort(files);
    if(n > 1000)
        result.resize(1000);


}

int main(){

    vector<string> result;
    int n =1010;

    sort_the_files(n, result);

    n = result.size();
    cout << " Final result array: ";
    for(int i=0; i<n; i++){
        cout<< result[i] << endl;
    }

    return 1;
}
