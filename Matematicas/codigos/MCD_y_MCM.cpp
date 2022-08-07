#include <iostream>

using namespace std;

int MCD(int a, int b) {
	if(b) return MCD(b, a % b);
	return a;
}

int MCM(int a, int b) {
	return a*(b/MCD(b, a % b));
}

int main() {
	int x, y;

	while(cin >> x >> y, x | y) {
		cout << "MCD = " << MCD(x, y) << endl;
	}

	while(cin >> x >> y, x | y) {
		cout << "MCM = " << MCM(x, y) << endl;
	}

	return 0;
}
