// Program to Find Total Number of Unique Paths in a Maze from Source to Destination
// https://www.techiedelight.com/find-total-number-unique-paths-maze-source-destination/
// Using BackTracking

#include<bits/stdc++.h>
using namespace std;
#define N 4

int vis[N][N];

bool isValid(int x, int y){

	if(x >= 0 and y >= 0 and x < N and y < N) return true;
	return false;
}

void countPaths(int maze[N][N], int x, int y, int &cnt){

	if(x == N - 1 and y == N - 1){
		cnt++;
		return;
	}
	
	vis[x][y] = 1;

	if(isValid(x,y) and maze[x][y]){

		if((x + 1) < N and !vis[x + 1][y]) countPaths(maze, x + 1, y, cnt);
		if((y + 1) < N and !vis[x][y + 1]) countPaths(maze, x, y + 1, cnt);
		if((x - 1) >= 0 and !vis[x - 1][y]) countPaths(maze, x - 1, y, cnt);
		if((y - 1) >= 0 and !vis[x][y - 1]) countPaths(maze, x, y - 1, cnt);
	}

	vis[x][y] = 0;		// BackTrack
}

int main(){

	int maze[N][N] = {
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	};

	int cnt = 0;

	countPaths(maze, 0, 0, cnt);

	cout<<"Total Number of Unique Paths: "<<cnt;

	return 0;
}