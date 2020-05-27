// Program to Find All Distinct Subsets of an Array
// https://leetcode.com/problems/subsets-ii/
/*
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    
    vector <vector<int>> res;
    
    void go(vector <int> &nums, vector <int> &v, int index){
        
        for(int i = index; i < nums.size(); i++){
		
            if(i > index and nums[i] == nums[i-1]) continue;
            
	    v.push_back(nums[i]);
            res.push_back(v);
            go(nums, v, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector <int> v;
        res.push_back(v);
        go(nums, v, 0);
        
        return res;
    }
};
