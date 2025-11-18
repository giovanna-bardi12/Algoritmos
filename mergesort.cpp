#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge (vector<int>& arr, int l, int r ){ 
    int tamanho = arr.size(); //ache o tamamnho do vector
    vector<int> tempArr(tamanho); //crie lista temporaria com o mesmo tamanho

    for (int i=l; i<=r; i++){ 
        tempArr[i] = arr[i];
    }

    int m = (l+r)/2; 
    int i1 = l;
    int i2 = m+1;

    for(int cur = l; cur <= r; cur++){
        if (i1 == m+1){
            arr[cur] = tempArr[i2++];

        }else if(i2 > r){
            arr[cur] = tempArr[i1++];

        }else if (tempArr[i1] <= tempArr[i2]){
            arr[cur] = tempArr[i1++];

        }else{
            arr[cur] = tempArr[i2++];
        }

    }


}

void mergesort(vector<int>& arr,int l,int r){
    if (l<r){
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, r);
    }
}

int main(){
//cin de forma otimizada
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);

//declarando variáveis
int c,n;

std::cin >> c;
for(int i = 0; i < c; i++){

    std::cin >> n;
    vector<int> myarr(n); //declarando vector de tamamnho n

    for (int k = 0; k<n; k++ ){ //preenchendo vector com as entradas
        cin >> myarr[k];
    }

    mergesort(myarr,0,n-1);

    for (int k = 0; k<n; k++ ){  //printando vector
        cout << myarr[k] << " ";

    }
    cout << "\n";
 
}



return 0;
}
