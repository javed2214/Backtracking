// Split an Array into Two Equal Subarrays

#include<bits/stdc++.h>
using namespace std;

void splitArray(int *a, int n){

	int leftSum=0;
	for(int i=0;i<n;i++)
		leftSum+=a[i];

	int rightSum=0,i=n-1,x;
	for(int i=n-1;i>=0;i--){
		rightSum+=a[i];
		leftSum-=a[i];
		if(leftSum==rightSum){
			x=i;
			break;
		}
	}
	for(int j=0;j<n;j++){
		if(j==x) cout<<"\n";
		cout<<a[j]<<" ";
	}
}

int main(){

	int a[]={1,2,3,4,5,5};
	int n=sizeof(a)/sizeof(int);

	splitArray(a,n);

	return 0;
}