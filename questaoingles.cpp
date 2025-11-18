#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string binarySearch(vector<string>& arr, string chave){
    int l = 0;
    int r = arr.size() - 1;

    while(l <= r){
        int m = (l + r)/2;
        if(chave == arr[m]){
            return arr[m];
        }else if(chave < arr[m]){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return "false";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numPalavras, chutes, acertos;
    acertos = 0;
    cin >> numPalavras;
    vector<string>palavras(numPalavras);

    for(int i = 0; i < numPalavras; i++){
        cin >> palavras[i];
    }

    cin >> chutes;
    vector<string>palavrasChute(chutes);
    for(int i = 0; i < chutes; i++){
        cin >> palavrasChute[i];
    }
    
    for(int k = 0; k < chutes; k++){
        string tentativa = palavrasChute[k];
        string resposta = binarySearch(palavras, tentativa);
        if(!(resposta == "false")){
            acertos += 1;
        }
    }

    cout << acertos << "\n";
    

    return 0;
}