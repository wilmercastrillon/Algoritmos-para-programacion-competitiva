#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

bool memo[5][50];

void pre(vector<int> &num){
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

int main(){
    vi n;
    n.push_back(1);
    n.push_back(3);
    n.push_back(5);
    pre(n);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 20; j++){
            printf("%3d", memo[i][j]);
        }
        printf("\n");
    }
    int m = 6;
    if(memo[n.size() - 1][m]) cout << "existe subconjunto\n";
    else cout << "no existe subconjunto\n";

    return 0;
}

