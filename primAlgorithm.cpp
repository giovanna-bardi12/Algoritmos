#include <iostream>
#include <algorithm>
#include<vector>
#include<tuple>
#include<queue>
#include<climits>
using namespace std;
using item = tuple<int,int,int>;
struct graph
{
    vector<vector<pair<int,int>>> matriz;
    vector<int> mark;
    int numEdges;

    graph (int n){
        matriz = vector<vector<pair<int,int>>> (n);
        mark = vector<int>(n, 1);
        numEdges = 0;
    }
};

void addEdge(graph& g,int u, int v, int val){
    g.matriz[v].push_back({u, val});
    g.matriz[u].push_back({v, val});
    g.numEdges++;
}

void Prim(graph& g, vector<int>& d, vector<int>& v){
    int infinito = INT_MAX;
    for(int i = 0; i < g.matriz.size(); i++){
        d[i] = infinito;
        v[i] = -1;
        g.mark[i] = -1;
    }
    
    priority_queue<item, vector<item>, greater<item>> h; //min heap
    h.push({0,0,0}); // custo - pai - dest
    d[0] = 0;

    for(int i = 0; i < g.matriz.size(); i++){
        int dest, pai;
        do
        {
            if(h.empty()) return;

            auto item = h.top();
            h.pop();  
            dest = get<2>(item);
            pai = get<1>(item);
            
            
        } while (g.mark[dest] == 1);

        g.mark[dest] = 1;
        v[dest]= pai;
        
        for(auto& e : g.matriz[dest]){
            int w = e.first;
            int dw = e.second;
            if(g.mark[w] != 1 && d[w] > dw){
                d[w] = dw;
                h.push({dw, dest, w});
            }
        }
    
    }

}


int main(){
    int qtdCid, qtdob, i, j, p;
    
    cin >> qtdCid >> qtdob;
    graph g(qtdCid);
    vector<int> dist(qtdCid);
    vector<int> ancestrais(qtdCid);

    for(int s = 0; s < qtdob; s++){
        cin >> i >> j >> p;
        addEdge(g,i,j,p);
    }

    Prim(g,dist,ancestrais);

    int somador = 0;

    for(int k = 0; k < dist.size(); k++){
        somador += dist[k];
    }
    cout << somador << "\n";


    return 0;
}