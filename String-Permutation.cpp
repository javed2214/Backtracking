// Program to Generate All Permutation of String
// Using Backtracking

#include<bits/stdc++.h>
using namespace std;

void getPermu(string str, int l, int r){

	if(l==r){
		cout<<str<<" ";
		return;
	}
	else{
		for(int i=l;i<=r;i++){
			swap(str[i],str[l]);
			getPermu(str,l+1,r);
			swap(str[i],str[l]);    // Backtracking
		}
	}
}

int main(){

	string str="ABCD";
	getPermu(str,0,str.length()-1);

	return 0;
}