#include <bits/stdc++.h>

using namespace std;

int v[46];

void dp(){
    v[0] = 0; v[1] = 1;
    for(int i = 2; i < 46; i++){
        v[i] = v[i-1] + v[i-2];
    }
}

int fibo(int x){
    if(x <= 1){
        return x;
    }else{
        return fibo(x-1) + fibo(x-2);
    }
}

int tab[46];
int fibonacci(int x){
    if(tab[x] != -1) return tab[x];

    if(x <= 1){
        return tab[x] = x;
    }else{
        return tab[x] = fibonacci(x-1) + fibonacci(x-2);
    }
}

int main(){
    memset(tab, -1, sizeof(tab));
    int n;
    while(scanf("%d", &n)){
        printf("%d\n", fibonacci(n));
    }

    return 0;
}
