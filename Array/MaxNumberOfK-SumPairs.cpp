//Leetcode -> 1679 (https://leetcode.com/problems/max-number-of-k-sum-pairs/)
// modifed version of two sum 
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums.size()-1,cnt=0;
        while(s<e){
            // if the sum is equal to k then we get a pair 
            if(nums[s] + nums[e] == k){
                cnt++;
                s++;
                e--;
            }
            // if the sum of the pair is greater then shift end pointer(e)
            else if(nums[s] +nums[e]> k ){
                e--;
            }
            // if the sum of the pair is lesser than the k then move forward the start pointer(s)
            else{
                s++;
            }
        }
        return cnt;
    }
};
/*
 Time Complexity -> O(NlogN)
 Space Complexity -> O(1)
 */
