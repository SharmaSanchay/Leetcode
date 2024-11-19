//Leetcode -> 2461 (https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int s = 0, e = 0;
        long long maxsum = 0, sum = 0;
        
        while(e < nums.size()){
            sum += nums[e];
            m[nums[e]]++;
            
            if(e - s + 1 == k){
                if(m.size() == k){ // All elements in the window are unique
                    maxsum = max(maxsum, sum);
                }
                
                sum -= nums[s];
                m[nums[s]]--;
                if(m[nums[s]] == 0) m.erase(nums[s]);
                s++;
            }
            
            e++;
        }
        
        return maxsum;
    }
};
/*
Time Complexity->0(N)
Space Complexity->0(N)
*/
