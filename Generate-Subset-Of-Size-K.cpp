// Program to Generate All the Subsets of an Array of Size K

#include<bits/stdc++.h>
using namespace std;

void getSubSets(vector<int> &v, int k, int ind, vector<int> ans, vector<vector<int>> &res){

	if(ans.size()==k){
		res.emplace_back(ans);
		return;
	}
	for(int i=ind;i<v.size();i++){
		ans.emplace_back(v[i]);
		getSubSets(v,k,i+1,ans,res);
		ans.pop_back();
	}
}

int main(){

	std::vector<int> v,ans;
	v={1,2,3,4,5};
	int k=3;

	vector <vector<int>> res;
	getSubSets(v,k,0,ans,res);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}

	return 0;
}