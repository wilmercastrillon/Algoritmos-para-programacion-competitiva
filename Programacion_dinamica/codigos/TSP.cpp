#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAX 15
#define inf 1000000000

using namespace std;

int n, target, grafo[MAX][MAX], memo[1 << MAX][MAX];

int dp(int mask, int v) {
	if(mask == target)
		return grafo[v][0];
	if(memo[mask][v] != -1)
		return memo[mask][v];

	int ans = inf;
	for(int i = 0; i < n; i++) {
		if(!(mask & (1<<i) )) {
			ans = min(ans, dp(mask | (1 << i), i) + grafo[v][i]);
		}
	}

	return memo[mask][v] = ans;
}

int main() {
	int m, x, y, z;
	scanf("%d %d", &n, &m);

	memset(grafo, 5436, sizeof(grafo));
	memset(memo, -1, sizeof(memo));

	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		grafo[x][y] = z;
		grafo[y][x] = z;
	}

	target = (1 << n) - 1;
	printf("%d\n", dp(1, 0));

	return 0;
}

/*
6 10
0 2 4
0 4 14
0 5 12
1 3 4
1 4 5
1 5 3
2 3 14
2 4 1
3 4 11
4 5 10
*/
