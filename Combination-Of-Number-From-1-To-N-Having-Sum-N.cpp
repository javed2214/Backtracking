// Combination of Number from 1 to N having Sum 'n'
// https://www.techiedelight.com/print-all-combination-numbers-from-1-to-n/

#include<bits/stdc++.h>
using namespace std;

void printCombination(vector <int> &v){

	for(auto it:v) cout<<it<<" ";
	cout<<endl;
}

void Combi(int index, int n, vector <int> &v){

	if(n == 0) printCombination(v);

	for(int i=index;i<=n;i++){
		v.push_back(i);
		Combi(i, n-i, v);
		v.pop_back();	// Backtrack
	}
}

int main(){

	int n;
	cin >> n;

	vector <int> v;

	Combi(1,n,v);

	return 0;
}