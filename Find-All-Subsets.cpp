// Program to Find all Subsets of an Array/Vector using Backtracking
// Time Complexity => O(2^n)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void getSubsets(vector<int> &v, vector<int> &subset, int ind){

	for(int i=ind;i<v.size();i++){

		subset.push_back(v[i]);
		
		res.push_back(subset);
		
		getSubsets(v,subset,i+1);
		
		subset.pop_back();
	}
}

void subsetUtil(vector<int> &v){

	vector<int> subset;

	res.push_back(subset);
	getSubsets(v,subset,0);
}

int main(){

	vector<int> v={1,2,3,4};

	subsetUtil(v);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}
	return 0;
}

