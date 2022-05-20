#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n = 9, V[9], SP[9][5];

void construir(){
    for(int i = 0; i < n; ++i)
        SP[i][0] = V[i];

    int x = log2(n);
    for(int j = 1; j <= x; ++j)
        for(int i = 0; i+(1<<j)-1 < n; ++i)
            SP[i][j] = min(SP[i][j-1], SP[i+(1<<(j-1))][j-1]);
}

int consulta(int L, int R){
    int res = 0;
    while(L <= R){
        int j = log2(R-L+1);
        res += SP[L][j];
        L += 1<<j;
    }
    return res;
}

int consulta_idempotentes(int L, int R){
    int j = log2(R-L+1);
    return min(SP[L][j], SP[R-(1<<j)+1][j]);
}

//1 9 2 2 7 4 2 1 7
int main(){
    n = 9;
    for(int i = 0; i < n; ++i)
        scanf("%d", &V[i]);

    construir();
    printf("%d", consulta(1, 6));
}
