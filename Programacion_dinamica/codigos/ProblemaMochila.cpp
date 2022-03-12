#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N, C, W[100], V[100], memo[100][100];

int dp(int i, int x){
    if(i == N) return 0;
    if(memo[i][x] != -1) return memo[i][x];

    if(x+W[i] <= C)
        return memo[i][x] = max(dp(i+1,x), dp(i+1,x+W[i])+V[i]);
    else
        return memo[i][x] = dp(i+1,x);
}

int main(){
    int w, c;

    while(scanf("%d", &C) != EOF){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d %d", &W[i], &V[i]);
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0, 0));
    }

    return 0;
}

/*
10
6
1 2
2 7
4 5
5 9
4 5
2 3
*/
