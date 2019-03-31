// Print All Combinations of Balanced Parentheses using Backtracking

#include<bits/stdc++.h>
using namespace std;

void printParentheses(string str, int n, int open, int close){

	if(close==n){
		cout<<str<<"\n";
		return;
	}
	else{
		if(open > close){
			str+="}";
			printParentheses(str,n,open,close+1);
			str.pop_back();
		}
		if(open < n){
			str+="{";
			printParentheses(str,n,open+1,close);
			str.pop_back();
		}
	}
}

int main(){

	int n=3;
	string str;

	cout<<"For n=3:\n";
	
	printParentheses(str,n,0,0);

	return 0;
}