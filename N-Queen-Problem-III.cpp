// Program to Print All Possible Solutions of N-Queen Problem

#include<bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<string>> &board){

	static int sol=1;
	cout<<"Solution: "<<sol<<"\n";
	sol+=1;
	for(auto it:board){
		for(auto pt:it)
			cout<<pt<<" ";
		cout<<"\n";
	}
	cout<<"\n\n";
	return;
}

bool isSafe(vector<vector<string>> &board, int row, int col, int n){

	for(int i=0;i<col;i++)
		if(board[row][i]=="Q")
			return false;

	for(int i=row,j=col;i>=0 and j>=0;i--,j--)
		if(board[i][j]=="Q")
			return false;

	for(int i=row,j=col;i<n and j>=0;i++,j--)
		if(board[i][j]=="Q")
			return false;

	return true;
}

bool solveNQueens(vector<vector<string>> &board, int col, int n){

	if(col==n){
		printSolution(board);
		return true;
	}

	bool res=false;
	for(int i=0;i<n;i++){
		if(isSafe(board,i,col,n)){
			board[i][col]="Q";
			res=solveNQueens(board,col+1,n) or res;
			board[i][col]=".";
		}
	}
	return res;
}

int main(){

	int n;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"\n";

	vector<vector<string>> board(n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i].push_back(".");

	solveNQueens(board,0,n);

	return 0;
}