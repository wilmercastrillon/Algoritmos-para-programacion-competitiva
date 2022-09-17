#include <iostream>

using namespace std;

const int MAX = 100;

int B[MAX] = { -1 };

void bordes(string p) {
	B[0] = -1; B[1] = 0;
	int j = 0;
	for(int i = 1; i < p.size(); i++) {
		while(j >= 0 && p[j] != p[i]) j = B[j];
		B[i + 1] = ++j;
	}
}

void KMP(string t, string p) {
	int j = 0;
	for(int i = 0; i < t.size(); i++) {
		while(j >= 0 && p[j] != t[i]) j = B[j];
		j++;
		if(j == p.size()) {
			cout << "match en rango (" << (i - j + 1) << "," << i << ")\n";
			j = B[j];
		}
	}
}

int main() {
	string substr = "ABRACABRAABRA";
	bordes(substr);

	for(int i = 0; i < substr.size() + 1; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	string str = "ABRACABRACABRAABRAX";
	KMP(str, substr);

	return 0;
}
