#include <iostream>
#include <vector>
#define debug(x) cerr << "\n" << (#x) << " is " << (x) << endl;

using namespace std;
const int MAX = 16;

int ft[MAX], n = 16;

struct fenwick_tree {//indexando desde 1
	
	fenwick_tree() {
		for(int i = 0; i < n; ++i) ft[i] = 0;
	}

	void update(int idx, int valor) {
		int x = ~idx, lsb = 0;

		while(lsb < n) {
			ft[idx + lsb + 1] += valor;
			lsb ^= x & -x;
			x = x ^ (x & -x);
		}
	}

	void construir(vector<int> &v) {
		for(int i = 0; i < v.size(); ++i) {
			update(i, v[i]);
		}
	}

	int query(int i) {
		int res = 0, lsb = 0;

		while(i > 0) {
			res += ft[i];
			lsb = i & -i;
			i = i ^ lsb;
		}
		return res;
	}

	int query(int i, int j) {
		return query(j) - query(i - 1);
	}
};

int main() {
	vector<int> v = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	fenwick_tree f;
	f.construir(v);

	int x, y;

	while(cin >> x >> y) {
		cout << f.query(x, y) << endl;
	}

	return 0;
}
