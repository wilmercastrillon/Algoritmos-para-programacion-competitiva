#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100;

struct union_find{
    int padre[100];

    void build(int n){
        for(int i = 0; i < n; i++) padre[i] = i;
    }

    int buscar(int v){//find
        if(v == padre[v]) return v;
        else return buscar(padre[v]);
    }

    void unir(int u, int v){//union
        u = buscar(u);  v = buscar(v);
        if(u != v) padre[u] = v;
    }

    bool MismoGrupo(int u, int v){
        return buscar(u) == buscar(v);
    }
};

struct union_find_rangos{
    int padre[100], rango[100];

    void build(int n){
        for (int i = 0; i < n; i++){
            padre[i] = i;  rango[i] = 0;
        }
    }

    void unir(int u, int v){
        u = buscar(u);  v = buscar(v);
        if(u == v) return;
        if(rango[u] > rango[v]){
            padre[v] = u;
            return;
        }
        padre[u] = v;
        if(rango[v] == rango[u]) rango[v]++;
    }

    int buscar(int x){//find
        if(x == padre[x]) return x;
        else return buscar(padre[x]);
    }

    bool MismoGrupo(int x, int y){return buscar(x) == buscar(y);}
};

int main(){

	union_find uf;

	uf.build(10);
	uf.unir(0, 1);
	uf.unir(2, 3);
	uf.unir(8, 9);

	uf.unir(3, 0);
	uf.unir(8, 7);

	uf.unir(4, 5);
	uf.unir(5, 6);
	uf.unir(0, 6);

	for(int i = 0; i < 10; i++) cout << i << " ";
	cout << endl;

	for(int i = 0; i < 10; i++)
	cout << uf.padre[i] << " ";
	cout << endl;

	//uf.grupo_n(5);

	if(uf.MismoGrupo(4, 1))
		cout << "si" << endl;
	else
		cout << "no" << endl;

	return 0;
}
