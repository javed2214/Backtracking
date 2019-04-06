// Program to Find all Subsets of an Array/Vector using Backtracking
// Time Complexity => O(2^n)

#include<bits/stdc++.h>
using namespace std;

void getSubsets(vector<int> &v, vector<vector<int>> &res, vector<int> &subset, int ind){

	for(int i=ind;i<v.size();i++){
		subset.push_back(v[i]);
		res.push_back(subset);
		getSubsets(v,res,subset,i+1);
		subset.pop_back();
	}
}

vector<vector<int>> subsetUtil(vector<int> &v){

	vector<int> subset;
	vector<vector<int>> res;

	res.push_back(subset);
	getSubsets(v,res,subset,0);

	return res;
}

int main(){

	vector<int> v={1,2,3,4};
	vector<vector<int>> res;

	res=subsetUtil(v);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}
	return 0;
}
