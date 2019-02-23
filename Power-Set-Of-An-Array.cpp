// Program to Print All the Power Set of a Vector/Array
// EX: [1,2,3] => {},{1},{1,2},{1,2,3},{2},{2,3},{3},{1,3}
// No of Power Sets :- 2^n
// Using Recursion

#include<bits/stdc++.h>
using namespace std;

void getPowerSet(std::vector<int> &v, int ind, vector<int> ans, vector<vector<int>> &res){

	if(v.size()==ind){
		res.emplace_back(ans);
		return;
	}
	ans.emplace_back(v[ind]);		// Including Current Element
	getPowerSet(v,ind+1,ans,res);
	
	ans.pop_back();					// Not Including Current Element
	getPowerSet(v,ind+1,ans,res);
}

int main(){

	std::vector<int> v,ans;
	v={1,2,3,4};
	vector <vector<int>> res;
	getPowerSet(v,0,ans,res);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}
	return 0;
}