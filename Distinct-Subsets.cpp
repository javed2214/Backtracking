// Program to Find all Distinct Subsets

#include<bits/stdc++.h>
using namespace std;

void findSubsets(vector<int> &v, vector<int> &ans, vector<vector<int>> &res, int ind){

	for(int i=ind;i<v.size();i++){
		ans.push_back(v[i]);
		res.push_back(ans);
		findSubsets(v,ans,res,i+1);
		ans.pop_back();
		while(i<v.size() and v[i]==v[i+1]) i++;
	}
}

int main(){

	vector<int> v={1,2,2};

	vector<int> ans;
	vector<vector<int>> res;
	res.push_back(ans);
	cout<<"[";

	findSubsets(v,ans,res,0);

	for(auto it:res){
		cout<<"[";
		for(auto pt:it)
			cout<<pt<<" ";
		cout<<"\b]\n";
	}

	return 0;
}