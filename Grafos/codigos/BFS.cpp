#include<iostream>
#include<queue>
#include<vector>

using namespace std;
typedef vector<int> vi;

vector<vector<int>> grafo(10);
bool visitado[10];

void bfs(int nodo){
    queue<int> cola;
    cola.push(nodo);  visitado[nodo] = true;

    while(cola.size()){
        nodo = cola.front();  cola.pop();

        for(int i = 0; i < grafo[nodo].size(); i++){
            if(!visitado[grafo[nodo][i]]){
                cola.push(grafo[nodo][i]);
                visitado[grafo[nodo][i]] = true;
            }
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
    bfs(1);
}
