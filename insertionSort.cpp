#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int tam){
    for(int i = 1; i<tam; i++){
        int v = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>v){
            arr[j + 1] = arr[j];
            j = j -1;
        };

        arr[j+1] = v;
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(nullptr);

    int tam;
    cin >> tam;
    vector<int> myarr(tam);

    for(int i=0; i<tam; i++){
        cin>> myarr[i];
    }

    insertionSort(myarr,tam);

    for(int i = 0; i<tam; i++){
        cout<< myarr[i] << " ";
    }
    cout<<"\n";

    return 0;
}