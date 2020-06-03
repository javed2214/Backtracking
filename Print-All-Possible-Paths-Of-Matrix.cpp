// Program to Print all Possible Paths from Top Left to Bottom Right of a Matrix

#include<bits/stdc++.h>
using namespace std;

vector <int> v;

void printVector(vector <int> &v){
    for(auto it: v)
        cout << it << " ";
    cout << endl;
}

void go(vector <vector<int>> &nums, int x, int y, int r, int c, vector<vector<int>> &vis){

    if(x < 0 or x > r or y < 0 or y > c or vis[x][y]) return;
    
    vis[x][y] = 1;
    v.push_back(nums[x][y]);

    if(x == r and  y == c) printVector(v);
    
    go(nums, x, y + 1, r, c, vis);  // Visit Right
    go(nums, x + 1, y, r, c, vis);  // Visit Down
    
    v.pop_back();       // BackTrack
    vis[x][y] = 0;      // BackTrack
}

int main(){

    int r, c;
    cin >> r >> c;

    vector <vector<int>> nums(r, vector<int> (c, 0));

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> nums[i][j];

    vector <vector<int>> vis(r, vector<int>(c, 0));
    vector <int> v;

    go(nums, 0, 0, r - 1, c - 1, vis);

    return 0;
}
