#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
bool grafo[10][10];

void construir_grafo(){
    memset(grafo, false, sizeof(grafo));
    grafo[1][5] = true;
    grafo[1][3] = true;
    grafo[1][2] = true;
    grafo[5][4] = true;
    grafo[2][3] = true;
}
*/

vector<vector<int>> grafo(10);

void construir_grafo(){
    grafo[1].push_back(5);
    grafo[1].push_back(3);
    grafo[1].push_back(2);
    grafo[5].push_back(4);
    grafo[2].push_back(3);
}

/*
typedef pair<int, int> ii;
vector<ii> grafo;

void construir_grafo(){
    grafo.push_back(ii(1, 5));
    grafo.push_back(ii(1, 3));
    grafo.push_back(ii(1, 2));
    grafo.push_back(ii(5, 4));
    grafo.push_back(ii(2, 3));
}
*/

int main(){
    int n = 5;
    construir_grafo();
}
