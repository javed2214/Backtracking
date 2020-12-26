// Program to Find Longest Possible Routes in a Matrix
// Using BackTracking

#include<bits/stdc++.h>
using namespace std;
#define M 10
#define N 10

int vis[M][N];

bool isValid(int x, int y){

	if(x >= 0 and y >= 0 and x < M and y < N) return true;
	return false;
}

bool isSafe(int mat[M][N], int x, int y){

	if(mat[x][y] == 1 and !vis[x][y]) return true;
	return false;
}

void findLongestPath(int mat[N][N], int i, int j, int x, int y, int &max_dist, int dist){

	if(i == x and j == y){

		max_dist = max(max_dist, dist);
		return;
	}

	vis[i][j] = 1;

	if(isValid(i + 1, j) and isSafe(mat, i + 1, j)) findLongestPath(mat, i + 1, j, x, y, max_dist, dist + 1);
	if(isValid(i - 1, j) and isSafe(mat, i - 1, j)) findLongestPath(mat, i - 1, j, x, y, max_dist, dist + 1);
	if(isValid(i, j + 1) and isSafe(mat, i, j + 1)) findLongestPath(mat, i, j + 1, x, y, max_dist, dist + 1);
	if(isValid(i, j - 1) and isSafe(mat, i, j - 1)) findLongestPath(mat, i, j - 1, x, y, max_dist, dist + 1);

	vis[i][j] = 0;			// BackTrack
}

int main(){

	int mat[M][N] = {
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};

	int max_dist = 0;

	findLongestPath(mat, 0, 0, 5, 7, max_dist, 0);

	cout<<"Longest Route Length: "<<max_dist;

	return 0;
}
