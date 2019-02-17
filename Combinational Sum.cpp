// Combinational Sum using Backtracking
// Array=[2,3,6,7] and k=7
// Combinational Sum => [2,2,3] and [7]

#include<bits/stdc++.h>
using namespace std;

void Combination(vector<int> &v, int sum, vector<int> &ans, vector<vector<int>> &res, int ind){

	if(sum==0){
		res.push_back(ans);
		return;
	}
	for(int i=ind;i<v.size();i++){
		if(sum<v[i])
			break;
		ans.push_back(v[i]);
		Combination(v,sum-v[i],ans,res,i);
		ans.pop_back();
	}
} 

int main(){

	vector<int> v={2,3,4,5,6};
	int sum=8;

	sort(v.begin(),v.end());
	vector<int> ans;
	vector<vector<int>> res;

	Combination(v,sum,ans,res,0);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}
	return 0;
}
