// Program to Find All Unique Combinations of Given Sum

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void Combi(vector<int> v, int sum, vector<int> ans, int ind=0){

	if(sum==0){
		res.push_back(ans);
		return;
	}
	for(int i=ind;i<v.size();i++){
		if(sum-v[i]<0)
			break;
		else{
			ans.push_back(v[i]);
			Combi(v,sum-v[i],ans,i+1);
			ans.pop_back();
			while(i<v.size() and v[i]==v[i+1])
				i++;
		}
	}
}

int main(){

	vector<int> v={10,1,2,7,6,1,5};
	int sum=15;

	sort(v.begin(),v.end());
	
	vector<int> ans;
	Combi(v,sum,ans);
	
	for(auto it:res){
		for(auto ptr:it)
			cout<<ptr<<" ";
		cout<<"\n";
	}

	return 0;
}