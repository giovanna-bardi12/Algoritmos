#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int k){
    int tam = arr.size();
    int l = 0;
    int r = tam - 1;

    while(l<=r){
        int m = (l+r)/2;
        if(k == arr[m]){
            return m;
        }else if(k < arr[m]){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return -1;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, oQueProcuro;
    cin >> n;
    cin >> oQueProcuro;
    vector<int> myarr(n);

    for(int i = 0; i<n; i++){
        cin >> myarr[i];
    }

    int resultado = binarySearch(myarr,oQueProcuro);

    if(resultado == -1){
        cout << "Não existe esse valor na lista" << "\n";
    } else{
        cout << "Valor" << " " << myarr[resultado] << " " << "encontrado" << "\n";
    }

    return 0;
}