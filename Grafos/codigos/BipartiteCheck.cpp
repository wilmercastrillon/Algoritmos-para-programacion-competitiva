#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

void _print() { cout << "]" << endl;}
template<typename T, typename... V>
void _print(T t, V... v) { cout << "[" << t; if(sizeof...(v)) cout << "]"; _print(v...); }

typedef pair<int, int> ii;
vector<vector<int>> grafo;
bool color[200], used[200];

bool BipartiteCheck(int nodo){
    queue<ii> cola;
    cola.push(ii(nodo, 0));
    memset(used, false, sizeof(used));
    color[nodo] = 0;  used[nodo] = true;
    int auxnodo;

    while(cola.size()){
        ii x = cola.front();  cola.pop();
        nodo = x.first;
        bool newcolor = 1 - x.second;

        for(int i = 0; i < grafo[nodo].size(); ++i){
            auxnodo = grafo[nodo][i];
            if(used[auxnodo] && newcolor != color[auxnodo])
                return false;
            if(used[auxnodo]) continue;

            cola.push(ii(auxnodo, newcolor));
            color[auxnodo] = newcolor;
            used[auxnodo] = true;
        }
    }
    return true;
}

int main(){
    int n, m, x, y;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        grafo.assign(n, vector<int>());

        for(int i = 0; i < m; ++i){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        if(BipartiteCheck(0)){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }
    }
}


