#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef vector<int> vi;
/*
bool memo[5][50];
void dp(vector<int> &num){
    memset(memo, false, sizeof(memo));

    for(int i = 0; i < num.size(); i++){
        if(i){
            for(int j = 1; j < 50; j++){
                if(memo[i - 1][j]){
                    memo[i][j] = true;
                    memo[i][j + num[i]] = true;
                }
            }
        }
        memo[i][num[i]] = true;
    }
}
*/

int memo[10][50];
int dp(int n, int pos, vector<int> &num){
    if(memo[n][pos] != -1) return memo[n][pos];
    if(n == 0) return 1;
    if(n < 0 || pos >= num.size())
        return 0;

    if(dp(n-num[pos],pos+1,num)==1 || dp(n,pos+1,num)==1)
        return memo[n][pos] = 1;
    else return memo[n][pos] = 0;
}

int main(){
    vi n;
    n.push_back(1);
    n.push_back(3);
    n.push_back(5);
    //pre(n);

    /*for(int i = 0; i < 4; i++){
        for(int j = 0; j < 20; j++){
            printf("%3d", memo[i][j]);
        }
        printf("\n");
    }
    */

    int m;

    while(cin >> m){
        //if(memo[n.size() - 1][m]) cout << "existe subconjunto\n";
        //else cout << "no existe subconjunto\n";

        memset(memo,-1,sizeof(memo));
        if(dp(m,0,n) == 1) cout << "existe subconjunto\n";
        else cout << "no existe subconjunto\n";
    }

    return 0;
}

