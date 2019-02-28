// N-Queen Problem Using BackTracking
// The N Queen is a Problem of placing N Chess Queens on an N×N chessboard so that no Two Queens Attack each Other
// 4*4 Chess Board; No of Queens to Placed = 4

#include<bits/stdc++.h>
using namespace std;
const int N=4;

void printSolution(int board[N][N]){

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
}

bool isSafe(int board[N][N], int row, int col){

	int i,j;

	// Check Row on Left Side
	for(int i=0;i<col;i++){
		if(board[row][i])
			return false;
	}

	// Check Upper Diagonal on Left Side 
	for(i=row,j=col;i>=0 and j>=0;i--,j--){
		if(board[i][j])
			return false;
	}

	// Check Lower Diagonal on Left Side
	for(i=row,j=col;j>=0 and i<N;i++,j--){
		if(board[i][j])
			return false;
	}
	return true;
}

bool solveNQueen(int board[N][N], int col){

	if(col>=N) return true;		// Base Case
	for(int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;
			if(solveNQueen(board,col+1)) return true;
			board[i][col]=0;    // BackTrack
		}
	}
	return false;
}

int main(){

	int board[N][N]{

		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	if(solveNQueen(board,0)==false){
		cout<<"Solution doesn't Exist!";
		return 0;
	}
	printSolution(board);

	return 0;
}