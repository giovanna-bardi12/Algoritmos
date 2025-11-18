#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int r){
    vector<int> temp(arr.size());

    for(int i = l; i <= r; i++){
        temp[i] = arr[i];
    }

    int m = (l + r)/2;
    int i1 = l;
    int i2 = m + 1;

    for(int curr = l; curr <= r; curr++){
        if(i1 == m+1){
            arr[curr] = temp[i2++];

        }else if(i2 > r){
            arr[curr] = temp[i1++];

        }else if(temp[i1] <= temp[i2]){
            arr[curr] = temp[i1++];

        }else{
            arr[curr] = temp[i2++];

        }
    }
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l < r){
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l,r);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases, nBoard, soma;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        soma = 0;
        cin >> nBoard;
        vector<int> numbers(2 * nBoard);

        for(int i = 0; i < 2 * nBoard; i++){
            cin >> numbers[i];
        }

        mergeSort(numbers, 0, (2*nBoard) - 1);
        
        for(int j = 0; j < 2 * nBoard; j+= 2){
            int num = numbers[j];
            soma += num;
        }
        cout << soma << "\n";   

    }
    return 0;
}