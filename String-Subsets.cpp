// Program to Generate All the Subsets of a String using Backtracking

#include<bits/stdc++.h>
using namespace std;

void getSubsets(string str, int n, vector<char> &v, vector<vector<char>> &res, int ind){

	for(int i=ind;i<n;i++){
		v.push_back(str[i]);
		res.push_back(v);
		getSubsets(str,n,v,res,i+1);
		v.pop_back();
	}
}

int main(){

	string str="abc";
	int n=str.length();

	vector<char> v;
	vector<vector<char>> res;

	getSubsets(str,n,v,res,0);

	for(auto it:res){
		cout<<"{";
		for(auto ptr:it)
			cout<<ptr;
		cout<<"}\n";
	}

	return 0;
}