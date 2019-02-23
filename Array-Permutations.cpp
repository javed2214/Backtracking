// Program to Generate All Permutations of an Array

#include<bits/stdc++.h>
using namespace std;

void printArray(int *a, int n){

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void genPermu(int *a, int l, int r, int n){

	if(l==r)
		printArray(a,n);
	
	else{
		for(int i=l;i<=r;i++){
			swap(a[l],a[i]);
			genPermu(a,l+1,r,n);
			swap(a[l],a[i]);
		}
	}
}
			
int main(){

	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(int);
	genPermu(a,0,n-1,n);
    
	return 0;
}	
