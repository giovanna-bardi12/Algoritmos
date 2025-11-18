#include <iostream>
#include <vector>
using namespace std;

void heapBottomUpMAX(vector<int>& arr){
    int t = arr.size() - 1;
    for(int i = t/2; i >= 1; i--){

        int k = i;
        int v = arr[k];
        bool heap = false;

        while (!heap && 2*k <= t){
            int j = 2 * k;

            if(j < t){
                if(arr[j] < arr[j+1]){
                    j = j + 1;
                }
            }

            if(v>=arr[j]){
                heap = true;

            }else{
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

void heapsort(vector<int>& arr){
    int t = arr.size() - 1;
    for(int i = t; i >= 2; i--){ //alterado

        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;


        int k = 1; //altersdo
        int v = arr[k];
        bool heap = false;
        int m = i -1; //criado

        while (!heap && 2*k <= m){ //alterado
            int j = 2 * k;

            if(j < m){ //alterado
                if(arr[j] < arr[j+1]){
                    j = j + 1;
                }
            }

            if(v>=arr[j]){
                heap = true;

            }else{
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tam;

        cin >> tam;
        vector<int> myarr(tam + 1);

        for(int k = 1; k <= tam; k++){
            cin >> myarr[k];
        }

        heapBottomUpMAX(myarr);
        heapsort(myarr);

        for(int k = 1; k <= tam; k++){
                cout << myarr[k] << " ";
            }
            cout << "\n"; 
        
        
    
    return 0;
}
