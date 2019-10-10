// Letter Case Permutation - LeetCode
// https://leetcode.com/problems/letter-case-permutation/

#include<bits/stdc++.h>
using namespace std;

vector <string> v;

void backtrack(string s, int index){

	if(index == s.length()){
		v.push_back(s);
		return;
	}
	backtrack(s, index + 1);
	if(isalpha(s[index])){
		s[index] ^= 32;
		backtrack(s, index + 1);
	}
}

int main(){

	string s;
	cin>>s;

	backtrack(s,0);

	for(auto it:v) cout<<it<<" ";

	return 0;
}