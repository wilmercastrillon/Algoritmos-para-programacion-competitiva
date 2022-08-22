#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool esPrimo[1000005];
vector<int> primos;

void criba(int n) {
    memset(esPrimo, true, sizeof(esPrimo));
    esPrimo[0] = esPrimo[1] = false;

    for(int i = 2; i < n; ++i){
        if(!esPrimo[i]) continue;

        for(int j = i*i; j < n; j += i)
            esPrimo[j] = false;
        primos.push_back(i);
    }
}

int main() {
	int x, y;

    criba(1000);

    cout << primos.size() << " numeros primos\n";
	for(int i = 0; i < primos.size(); ++i){
        cout << primos[i] << "\n";
	}

	return 0;
}
