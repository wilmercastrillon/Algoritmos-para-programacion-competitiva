#include <iostream>
#include <string.h>

using namespace std;
/*
int V[] = {5,2,8,2,4,3,1}, memo[8];

void precalcular(){
    memo[0] = 0;
    for(int i = 0; i < 7; i++)
        memo[i+1] = V[i] + memo[i];
}

int consulta(int i, int j){ return memo[j] - memo[i-1]; }
*/
int M[20][20], memo[20][20], fila, col;

/*
1 9 6 3 7
7 5 3 0 5
0 7 6 5 3
7 8 9 5 0
9 5 3 7 8
*/

void precalcular(){
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= fila; i++)
    for (int j = 1; j <= col; j++)
        memo[i][j] = memo[i][j - 1] + memo[i - 1][j] +
                        M[i - 1][j - 1] - memo[i - 1][j - 1];
}

int consulta(int f1, int c1, int f2, int c2){
    return memo[f2][c2] - memo[f1-1][c2] -  memo[f2][c1-1] + memo[f1-1][c1-1];
}

int main(){
    fila = col = 5;
    for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> M[i][j];
    precalcular();

    cout << "tabla aditiva:" << endl;
    for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++)
			cout << memo[i][j] << "   ";
        cout << endl;
    }

    cout << consulta(2, 2, 3, 4) << endl;
    return 0;
}


