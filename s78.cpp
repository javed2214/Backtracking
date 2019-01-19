// Combinational Sum using Backtracking
// Array=[2,3,6,7] and k=7
// Combinational Sum => [2,2,3] and [7]

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define DB(x) cout<<#x<<"="<<x<<endl;
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define SIZE 1000000

void combinationaSum(std::vector<int> &v, int sum, std::vector<int> &r, std::vector<vector<int> > &res, int i){

	if(sum<0) return;
	if(sum==0){
		res.push_back(r);
		return;
	}
	while(i<v.size() and sum-v[i]>=0){

		r.push_back(v[i]);
		combinationaSum(v,sum-v[i],r,res,i);
		i++;
		r.pop_back();
	}
}

int main(){

	std::vector<int> v={2,3,6,7};
	std::vector<int> r;
	vector <vector<int> > res;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());  // To Remove Duplicates
	int sum=7;

	combinationaSum(v,sum,r,res,0);

	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}