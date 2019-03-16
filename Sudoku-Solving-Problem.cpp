// Sudoku Solving Problem using Backtracking
// https://www.geeksforgeeks.org/sudoku-backtracking-7/

#include<bits/stdc++.h>
using namespace std;
#define N 9
#define ZERO 0

bool fidUnassignedLocation(int grid[N][N], int &row, int &col){

	for(row=0;row<N;row++)
		for(col=0;col<N;col++)
			if(grid[row][col]==ZERO)
				return true;
	return false;
}

bool usedInRow(int grid[N][N], int row, int num){

	for(int col=0;col<N;col++)
		if(grid[row][col]==num)
			return true;
		return false;
}

bool usedInCol(int grid[N][N], int col, int num){

	for(int row=0;row<N;row++)
		if(grid[row][col]==num)
			return true;
	return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){

	for(int row=0;row<3;row++)
		for(int col=0;col<3;col++)
			if(grid[row+boxStartRow][col+boxStartCol]==num)
				return true;
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){

	return !usedInRow(grid,row,num) and
		   !usedInCol(grid,col,num) and
		   !usedInBox(grid,row-row%3,col-col%3,num) and
		   grid[row][col]==ZERO;
}

void printGrid(int grid[N][N]){

	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++)
			cout<<grid[row][col]<<" ";
		cout<<"\n";
	}
}

bool solveSudoku(int grid[N][N]){

	int row,col;

	if(!fidUnassignedLocation(grid,row,col))
		return true;

	for(int num=1;num<=9;num++){

		if(isSafe(grid,row,col,num)){
			grid[row][col]=num;
			if(solveSudoku(grid))
				return true;

			grid[row][col]=ZERO;
		}
	}
	return false;
}

int main(){

	int grid[N][N]={
		{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    if(solveSudoku(grid)==true)
    	printGrid(grid);
    else cout<<"Solution doesn't Exist!\n";

    return 0;
}