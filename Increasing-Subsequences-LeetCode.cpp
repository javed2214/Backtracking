// Increasing Subsequences LeetCode
// https://leetcode.com/problems/increasing-subsequences/

class Solution {
public:

    set<vector<int>> res;
    vector<int> v;
    
    void helper(vector<int> &nums, int index){
        
        if(v.size() >= 2)
            res.insert(v);
        
        for(int i=index;i<nums.size();i++){
            if(v.size() == 0 or nums[i] >= v.back()){
                v.push_back(nums[i]);
                helper(nums, i+1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        helper(nums,0);
        
        return vector<vector<int>> (res.begin(),res.end());		// Type Casting
    }
};