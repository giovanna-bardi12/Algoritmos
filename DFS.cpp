#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct graph{
    vector<vector<int>> matrizadj;
    int numEdges; //arestas
    vector<int> mark;
    vector<int> pre;
    vector<int> post;
};



class dfs{
    int tempglobal;

    graph createGraph(int n){
        graph g;
        g.mark = vector<int> (n); //vetor
        g.pre = vector<int> (n, 0); //vetor
        g.post = vector<int> (n, 0); //vetor
        g.matrizadj = vector<vector<int>> (n, vector<int> (n, 0)); //cria matriz nxn
        g.numEdges = 0;
        return g;
    }

    int first(graph& g, int v, int n){ //busca primeira aresta de saída
        for(int i = 0; i < n; i++){
            if(g.matrizadj[v][i] != 0) return i;
        }
        return n; //indicar que o vertice não tem vizinhos
    }

    int next(graph& g, int v, int w, int n){ //busca a proxima aresta de saída
        for(int i = w+1; i < n; i++){
            if(g.matrizadj[v][i] != 0) return i;
        }
        return n;
    }

    void setEdge(graph& g, int i, int j, int wt){ //adiciona uma aresta
        if(wt != 0){
            if(g.matrizadj[i][j]==0){
                g.numEdges ++;
            }
            g.matrizadj[i][j] = wt;
        }
    }

    void delEdge(graph& g, int i, int j){ //remove uma aresta
        if (g.matrizadj[i][j] != 0){
            g.numEdges --;
        }
        g.matrizadj[i][j] = 0;
    }
    
    void previsit(graph& g, int v){
        g.pre[v] = tempglobal ++;
    }

    void posvisit(graph& g, int v){
        g.post[v] = tempglobal ++;
    }

    void DFS(graph& g, int v, int n){
        previsit(g, v);
        g.mark[v] = 1;
        int w = first(g,v,n);

        while(w < n){
            if(g.mark[w] == 0){
                DFS(g,w,n);
            }

            w = next(g,v,w,n);
        }
        posvisit(g,v);
    }



    void graphTranverseDFS(graph& g, int n){
        for(int v = 0; v < n; v++){
            g.mark[v] = 0; //marcou como não visitado
        }
        for(int s = 0; s < n; s++){
            if(g.mark[s] == 0){
                DFS(g,s,n);
            }
        }
    }

};

int main(){
    graph G;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}

