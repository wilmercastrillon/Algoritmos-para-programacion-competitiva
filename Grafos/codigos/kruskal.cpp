#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct union_find {
	int padre[100];

	union_find(int n) {
		for (int i = 0; i < n; i++) padre[i] = i;
	}

	int buscar(int v) {
		if (v == padre[v]) return v;
		else return padre[v] = buscar(padre[v]);
	}

	void unir(int u, int v) { padre[buscar(u)] = buscar(v); }

	bool mismo_grupo(int x, int y) { return buscar(x) == buscar(y); }
};

#define mpiii(peso, inicio, destino) iii(peso, ii(inicio, destino))
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int kruskal(vector<iii>& grafo, int n) {
	sort(grafo.begin(), grafo.end());
	union_find uf(n+1);
	int peso = 0, cont = 0;

	for(int i = 0; i < grafo.size(); i++) {
		ii arista = grafo[i].second;
		if(!uf.mismo_grupo(arista.first, arista.second)) {
			uf.unir(arista.first, arista.second);
			peso += grafo[i].first;
			if(++cont == n - 1)
				return peso;
		}
	}
	return -1;
}

int main() {
	int n, m, x, y, z;

	while(scanf("%d %d", &n, &m) != EOF) {
		vector<iii> grafo;
		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &x, &y, &z);
			grafo.push_back(mpiii(z, x, y));
		}
		int MST = kruskal(grafo, n);
		printf("%d\n", MST);
	}
	
	return 0;
}

/*
in:
6 9
1 2 1
1 4 4
1 5 3
2 4 4
2 5 2
3 6 4
3 5 5
4 5 4
5 6 7

out: 16
*/
