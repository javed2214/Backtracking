// Generate All the Permutations of a Vector

#include<bits/stdc++.h>
using namespace std;

void Permutation(vector<int> &v, vector<vector<int>> &res, int start, int end){

	if(start==end){
		res.push_back(v);
		return;
	}
	for(int i=start;i<=end;i++){
		swap(v[i],v[start]);
		Permutation(v,res,start+1,end);
		swap(v[i],v[start]);
	}
}

int main(){

	vector<int> v={1,2,3};
	vector<vector<int>> res;

	int start=0;
	int end=v.size()-1;

	Permutation(v,res,start,end);

	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}
	return 0;
}