#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct graph{
    vector<vector<int>> matriz;
    vector <int> mark;
    vector <int> pre;
    vector <int> pos;
    int numEdge;

};

int tempglobal; 

graph creatGraph(int n){
    graph g;
    g.mark = vector<int> (n);
    g.pre = vector<int> (n, 0);
    g.pos = vector<int> (n, 0);
    g.matriz = vector<vector<int>> (n, vector<int> (n, 0));
    g.numEdge = 0;
    return g;
}

void addArestas(graph& g, int numA){
    for(int i = 0; i < numA; i++){
        int h,j;
        cin >> h >> j;
        g.matriz[h][j]=1;
        g.matriz[j][h]=1;
        g.numEdge++;
    }
}

int first(graph& g, int v, int n){
    for(int i = 0; i < n; i ++){
        if(g.matriz[v][i] != 0) return i;
    }
    return n;
}

int next(graph& g, int v, int w, int n){
    for(int i = w + 1; i < n; i++){
        if(g.matriz[v][i] != 0) return i;
    }
    return n;
}


void BFS( graph& g, int v, int n){
    queue<int> q;
    q.push(v);
    g.mark[v] = 1;

    while(q.size() > 0){
        int s = q.front();
        q.pop();
        int w = first(g, s, n);

        while (w < n){
          if(g.mark[w] == 0){
            g.mark[w] = 1;
            q.push(w);
          }  

          w = next(g, s, w, n);
        }
        
    }
}

int graphTraverse(graph& g, int n){
    int count = 0;
    for(int v = 0; v < n; v++){
        g.mark[v] = 0;
    }

    for(int v = 0; v < n; v++){
        if(g.mark[v] == 0){
            BFS(g,v, n);
            count ++;
        }
    }
    return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int casos, vert, ar;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        cin >> vert >> ar;
        graph G = creatGraph(vert);
        addArestas(G,ar);

        cout << graphTraverse(G, vert) << "\n";

    }
    
    return 0;
}