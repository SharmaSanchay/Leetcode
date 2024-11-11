// Leetcode -> 40 (https://leetcode.com/problems/combination-sum-ii/description/)
class Solution {
public:
void solve(vector<int>can,vector<int>&ans,vector<vector<int>>&res,int target,int idx,int&tempsum){
    // if the sum of the ans is equal target
    if (target == tempsum)
    {
        res.push_back(ans);
        return;
    }
    // base case
    if(idx>=can.size() || tempsum > target){
        return;
    }
    for(int i=idx;i<can.size();++i){
        if(i>idx && can[i]==can[i-1]){   // if the previous element is equal to the current then skip it
            continue;                    // if the i > idx   is ensure that the we don't consider the current twice 
        }
        ans.push_back(can[i]);
        tempsum += can[i];
        solve(can, ans, res, target, i + 1, tempsum);
        ans.pop_back();
        tempsum -= can[i];
    }
    return;
}
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(can.begin(), can.end());
        int idx = 0;
        int tempsum = 0;
        solve(can, ans, res, target, idx, tempsum);
        return res;
    }
};
/*
Time Complexity-> O(2^n)
Space Complexity->O(n)
*/