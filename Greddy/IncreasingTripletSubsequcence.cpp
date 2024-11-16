//Leetcode -> 334(https://leetcode.com/problems/increasing-triplet-subsequence/)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
	   if(nums.size()<3) return false;
	//make two pointer find left and mid
	/*left stores the min value in the vector
	  and  mid stores the value greater than left but lesser than its current value and when we get the value just greater than the mid then we return true otherwise false*/
        int left=INT_MAX,mid=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return true;
            if(nums[i]>left && nums[i]<mid) mid = nums[i];
            if(nums[i]<left) left=nums[i];
        }
        return false;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(1)
*/
