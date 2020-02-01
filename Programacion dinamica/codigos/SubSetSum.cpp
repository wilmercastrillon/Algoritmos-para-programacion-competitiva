#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

bool memo[10][5];
void dp(vector<int> &V){
    memset(memo, false, sizeof(memo));
    for(int i = 0; i < V.size(); i++){
        if(i){
            for(int j = 1; j < 10; j++)
                if(memo[j][i - 1]){
                    memo[j][i] = true;
                    memo[j + V[i]][i] = true;
                }
        }
        memo[V[i]][i] = true;
    }
}

/*
int memo[10][5];
int dp(int n, int k, vector<int> &V){
    if(memo[n][k] != -1) return memo[n][k];
    if(n == 0) return 1;
    if(n < 0 || k >= V.size()) return 0;

    if(dp(n-V[k],k+1,V)==1 || dp(n,k+1,V)==1)
        return memo[n][k] = 1;
    else return memo[n][k] = 0;
}
*/
int main(){
    vi n;
    n.push_back(1);
    n.push_back(3);
    n.push_back(5);
    dp(n);

    /*for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            printf("%3d", memo[i][j]);
        }
        printf("\n");
    }*/


    int m;

    while(cin >> m){
        if(memo[m][n.size() - 1]) cout << "existe subconjunto\n";
        else cout << "no existe subconjunto\n";

        //memset(memo,-1,sizeof(memo));
        //if(dp(m,0,n) == 1) cout << "existe subconjunto\n";
        //else cout << "no existe subconjunto\n";
    }

    return 0;
}

