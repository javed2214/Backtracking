// Knight Tour Problem - BackTracking

#include<bits/stdc++.h>
using namespace std;

#define n 8

// dx[] and dy[] should be as it is
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};    
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int mat[n][n], int x, int y){
    return (x >= 0 and x < n and y >= 0 and y < n and mat[x][y] == -1);
}

int go(int mat[n][n], int x, int y, int mv){

    if(mv == n * n) return 1;
    
    for(int i = 0; i < 8; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];

        if(isValid(mat, tx, ty)){
            mat[tx][ty] = mv;
            if(go(mat, tx, ty, mv + 1) == 1)
                return 1;
            else mat[tx][ty] = -1;
        }
    }
    return 0;
}

int main(){

    int mat[n][n];
    memset(mat, -1, sizeof(mat));
    mat[0][0] = 0;

    int x = 0;
    x = go(mat, 0, 0, 1);

    if(x){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
    }
    return 0;
}