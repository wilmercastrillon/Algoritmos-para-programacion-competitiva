#include <bits/stdc++.h>

using namespace std;

int T[5][5];
int memo[5][5];
int n = 4, m = 4;

int f(int i, int j){
    if(i==0 && j==0) return T[0][0];
    if(memo[i][j] != -1) return memo[i][j];

    if(i == 0) return memo[0][j] = T[0][j] + f(0, j-1);
    if(j == 0) return memo[i][0] = T[i][0] + f(i-1, 0);

    return memo[i][j]= T[i][j] + max(f(i-1, j), f(i, j-1));
}

void dp(){
    memo[0][0] = T[0][0];//caso base

    for(int i = 1; i < n; i++)//llenar filas
        memo[i][0] += memo[i-1][0] + T[i][0];

    for(int i = 1; i < m; i++)//llenar columnas
        memo[0][i] += memo[0][i-1] + T[0][i];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            memo[i][j] += max(memo[i - 1][j], memo[i][j - 1]) + T[i][j];
}

int main(){
    memset(memo, 0, sizeof(memo));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &T[i][j]);
        }
    }
    dp();
    printf("%d\n", memo[n-1][m-1]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%3d", memo[i][j]);
        }
        printf("\n");
    }
    return 0;
}


