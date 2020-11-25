// Combination of Number from 1 to N having Sum 'N'

#include<bits/stdc++.h>
using namespace std;

void printCombination(vector <int> &v){

	for(auto it:v) cout<<it<<" ";
	cout << endl;
}

void combinationSum(vector <int> &v, int n, int index){

	if(n == 0) printCombination(v);

	for(int i = index; i <= n; i++){

		v.push_back(i);
		
		combinationSum(v, n-i, i);
		
		v.pop_back();
	}
}

int main(){

	int n;
	cin >> n;

	vector <int> v;

	combinationSum(v,n,1);

	return 0;
}
