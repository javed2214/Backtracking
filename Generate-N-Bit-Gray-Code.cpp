// Program to Generate N-Bit Gray Code using BackTracking
// https://www.geeksforgeeks.org/backtracking-approach-generate-n-bit-gray-codes/

#include<bits/stdc++.h>
using namespace std;

void greyCodeUtil(vector <int> &res, int n, int &num){

	if(n == 0){
		 res.push_back(num);
		 return;
	}
	
	greyCodeUtil(res, n - 1, num);

	num = num ^ (1 << (n - 1));

	greyCodeUtil(res, n - 1, num);
}

vector <int> greyCode(int n){

	vector <int> res;

	int num = 0;
	greyCodeUtil(res, n, num);

	return res;
}

int main(){

	int n;
	cin>>n;

	vector <int> code = greyCode(n);

	for(int i=0;i<code.size();i++)
		cout<<code[i]<<" ";

	return 0;
}