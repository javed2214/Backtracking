// Program to Generate Valid Parentheses
// Given n Pairs of Parentheses, Write a function to Generate All Combinations of Valid Parentheses
// Ex: n=2 ()() and (())

#include<bits/stdc++.h>
using namespace std;

void getParenth(int openB, int closeB, int n, string str, vector <string> &v){

	if(closeB == n){
		v.push_back(str);
		return;
	}
	if(closeB < openB){
		str += ")";
		getParenth(openB, closeB + 1, n, str, v);
		str.pop_back();
	}
	if(openB < n){
		str += "(";
		getParenth(openB + 1, closeB, n, str, v);
		str.pop_back();
	}
}

int main(){

	int n=3;
	string str;
	vector <string> v;
	getParenth(0,0,n,str,v);

	for(auto it:v){
		for(auto ptr:it)
			cout<<ptr;
		cout<<"\n";
	}
	return 0;
}
