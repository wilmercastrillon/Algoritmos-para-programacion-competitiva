#include <bits/stdc++.h>

using namespace std;
/*
int v[45];

void dp(){
    v[0] = 0; v[1] = 1;
    for(int i = 2; i < 45; i++){
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
*/
int v[45];
int fibo(int x){
    if(v[x] != -1) return v[x];

    if(x <= 1){
        return v[x] = x;
    }else{
        return v[x] = fibo(x-1) + fibo(x-2);
    }
}

int main(){
    memset(v, -1, sizeof(v));
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", fibo(n));
    }

    return 0;
}
