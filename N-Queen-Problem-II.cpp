// N-Queen Problem using 2-D Vector

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<string>> &board, int row, int col, int n){

	for(int i=0;i<col;i++)
		if(board[row][i]=="Q")
			return false;

	for(int i=row,j=col;i>=0 and j>=0;i--,j--)
		if(board[i][j]=="Q")
			return false;

	for(int i=row,j=col;j>=0 and i<n;i++,j--)
		if(board[i][j]=="Q")
			return false;

	return true;
}

bool solveNQueens(vector<vector<string>> &board, int col, int n){

	if(col==n-1) return true;

	for(int i=0;i<n;i++){
		if(isSafe(board,i,col,n)){
			board[i][col]="Q";
			if(solveNQueens(board,col+1,n)) return true;
			board[i][col]=".";
		}
	}
	return false;
}

int main(){

	int n;
	cout<<"Enter n: ";
	cin>>n;

	vector <vector<string>> board(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			board[i].push_back(".");
	}

	solveNQueens(board,0,n);

	for(auto it:board){
		for(auto pt:it)
			cout<<pt<<" ";
		cout<<"\n";	
	}

	return 0;
}
