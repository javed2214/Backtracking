// Partition to K Equal Sum Subsets - LeetCode
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector <int> &v, vector <int> &vis, int start_index, int k, int cur_sum, int cur_num, int target){

	if(k == 1) return true;
	if(cur_sum == target and cur_num > 0) return canPartition(v, vis, 0, k - 1, 0, 0, target);
	for(int i=start_index;i<v.size();i++){
		if(!vis[i]){
			vis[i] = 1;
			if(canPartition(v, vis, i + 1, k, cur_sum + v[i], cur_num++, target))
				return true;
			vis[i] = 0;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector <int> &v, int k){

	int n = v.size();
	int sum = 0;
	for(auto it:v) sum += it;
	if(k <= 0 or sum % k != 0) return false;
	vector <int> vis(n,0);
	return canPartition(v, vis, 0, k, 0, 0, sum / k);
}

int main(){

	vector <int> v = {4,3,2,3,5,2,1};

	int k = 4;

	if(canPartitionKSubsets(v,k)) cout<<"Yes";
	else cout<<"No";

	return 0;
}