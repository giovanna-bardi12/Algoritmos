#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

struct graph{
    vector<vector<pair<ll,ll>>> lista;
    vector<int> mark;
    int numEdges;

    graph (int n){
        lista.resize(n);
        mark.resize(n, -1);
        numEdges = 0;
    }
};

void addEdge(graph& g, int u, int v, ll val){
    g.lista[u].push_back({v, val});
    g.lista[v].push_back({u, val});
    g.numEdges++;
}

void dijkstra(graph& g, int s, vector<ll>& d, vector<int>& predecessores){
    int n = g.lista.size();
    for(int i = 0; i < n; i++){
        d[i] = 10e18;
        predecessores[i] = - 1;
        g.mark[i] = -1;
    }

    priority_queue<pair<ll,int>> H;
    H.push({0, s});
    d[s]=0;

    for(int i = 0; i < n; i++){
        int v = -1;
        ll custoV = -1;
        do{
            if (H.empty()) return;
            custoV = -H.top().first;
            v = H.top().second;
            H.pop();

        }while(g.mark[v] == 1);
        g.mark[v] = 1;


        for(auto& e : g.lista[v] ){
            int w = e.first;
            ll dW = e.second;
            if(g.mark[w] == -1 && d[w] > d[v] + dW){
                d[w] = d[v] + dW;
                predecessores[w] = v;
                H.push({-d[w],w});
            }
        }
    }
}

int main(){
    int vert, ed, a, b;
    ll w;
    cin >> vert >> ed;

    graph g(vert);

    for(int i = 0; i < ed; i++){
        cin >> a >> b >> w;
        addEdge(g,a-1,b-1,w);
    }

    vector<ll> dist(vert);
    vector<int> predecessors(vert);

    dijkstra(g,0,dist,predecessors);

    int destino = vert - 1;

    if(dist[destino] == 10e18){
        cout << -1;

    }else{
        vector<int> caminho;
        int atual = destino;

        while(atual != -1 ){
            caminho.push_back(atual);
            atual = predecessors[atual];
        }


        reverse(caminho.begin(), caminho.end());

        for(int i = 0; i < caminho.size(); i++){
            cout << caminho[i] + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}


