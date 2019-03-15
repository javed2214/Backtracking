// Program to Print all Possible Paths from Top Left to Bottom Right of a Matrix

#include<bits/stdc++.h>
using namespace std;
#define N 3

void printPaths(vector<int> v){

	for(auto it:v) cout<<it<<" ";
	cout<<"\n";
}

void getAllPaths(int mat[N][N], int x, int y, vector<int> v){

	if(x==N-1){
		for(int i=y;i<N;i++)
			v.push_back(mat[x][i]);
		printPaths(v);
		return;
	}
	if(y==N-1){
		for(int i=x;i<N;i++)
			v.push_back(mat[i][y]);
		printPaths(v);
		return;
	}
	v.push_back(mat[x][y]);
	getAllPaths(mat,x+1,y,v);
	getAllPaths(mat,x,y+1,v);
}

int main(){

	int mat[N][N]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vector<int> v;
	getAllPaths(mat,0,0,v);
}