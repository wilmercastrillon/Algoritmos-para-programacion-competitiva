#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int MAX = 100;

vector<vector<int>> grafo(MAX);
bool visitado[MAX];

void dfs(int nodo, vector<int> &toposort){
    visitado[nodo] = true;
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(!visitado[grafo[nodo][i]])
            dfs(grafo[nodo][i], toposort);
    }
    toposort.push_back(nodo);
}

vector<int> toposort_dfs(int n){
    vector<int> toposort;
    memset(visitado, false, sizeof(visitado));

    for(int i = 0; i < n; ++i) {
        if(!visitado[i]) dfs(i, toposort);
    }
    reverse(toposort.begin(), toposort.end());
    return toposort;
}

int main(){
    int n = 6;
    grafo[0].push_back(2);
    grafo[0].push_back(4);
    grafo[1].push_back(4);
    grafo[1].push_back(5);
    grafo[2].push_back(3);
    grafo[2].push_back(4);
    grafo[4].push_back(5);

    vi res = toposort_dfs(n);

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
}
