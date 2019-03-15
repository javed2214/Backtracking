// Rat in Maze Problem
// Application of Backtracking
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

#include<bits/stdc++.h>
using namespace std;
#define N 4

void printSolution(int sol[N][N]){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<sol[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

bool isSafe(int maze[N][N], int x, int y){

	if(x>=0 and x<N and y>=0 and y<N and maze[x][y]==1) return true;
	return false;
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]){

	if(x==N-1 and y==N-1){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y)==true){

		sol[x][y]=1;

		if(solveMaze(maze,x+1,y,sol)==true) return true;
		if(solveMaze(maze,x,y+1,sol)==true) return true;

		sol[x][y]=0;
		return false;
	}
	return false;
}

void solveMazeUtil(int maze[N][N]){

	int sol[N][N]={
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	if(solveMaze(maze,0,0,sol)==false){
		cout<<"Soluation doesn't Exist!";
		return;
	}
	printSolution(sol);
	return;
}

int main(){

	int maze[N][N]={
		{1,0,0,0},
		{1,1,0,1},
		{0,1,0,0},
		{1,1,1,1}
	};
	solveMazeUtil(maze);

	return 0;
}