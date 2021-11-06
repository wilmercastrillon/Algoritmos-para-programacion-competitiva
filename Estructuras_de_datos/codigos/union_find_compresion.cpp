#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

const int MAX = 100;

struct union_find{
int padre[MAX];

void iniciar(int n){
    for (int i = 0; i < n; i++) padre[i] = i;
}

int buscar(int v){
    if(v == padre[v]) return v;
    else return padre[v] = buscar(padre[v]);
}

void unir(int u, int v){ padre[buscar(u)] = buscar(v); }

};

int main(){
    int n, m, x, y;
    scanf("%d %d", &n, &m);

	union_find uf;
    uf.iniciar(n+1);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        uf.unir(x, y);
    }

	for(int i = 0; i < n; i++) cout << i << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
	cout << uf.padre[i] << " ";
	cout << endl;

	return 0;
}
