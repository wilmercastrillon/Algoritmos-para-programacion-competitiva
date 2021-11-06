#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vector<int>> grafo(10);
bool visitado[10];

void dfs(int nodo){
    visitado[nodo] = true;
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(!visitado[grafo[nodo][i]]){
            dfs(grafo[nodo][i]);
        }
    }
}

void construir_grafo(){
    grafo[1].push_back(5);
    grafo[1].push_back(3);
    grafo[1].push_back(2);
    grafo[5].push_back(4);
    grafo[2].push_back(3);
}

int main(){
    int n = 5;
    construir_grafo();
    dfs(1);
}
