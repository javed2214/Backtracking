// Program to Generate all Binary String of N bits

#include<bits/stdc++.h>
using namespace std;

void printArray(int *a, int n){

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void genBinaryString(int *a, int n, int i){

	if(i==n){
		printArray(a,n);
		return;
	}
	a[i]=0;
	genBinaryString(a,n,i+1);
	a[i]=1;
	genBinaryString(a,n,i+1);
}

int main(){

	int n=3;
	int a[n];

	genBinaryString(a,n,0);

	return 0;
}