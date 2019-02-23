// Program to Print All the String Subsequences
// Recursive Approach

#include<bits/stdc++.h>
using namespace std;

void getSubSeq(string inp, string out){

	if(inp.length()==0){
		cout<<"{"<<out<<"}\n";
		return;
	}
	getSubSeq(inp.substr(1),out);
	getSubSeq(inp.substr(1),out+inp.substr(0,1));
}

int main(){

	string inp="abc";
	string out;

	getSubSeq(inp,out);

	return 0;
}