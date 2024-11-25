//Leetcode->239 (https://leetcode.com/problems/sliding-window-maximum/description/)
class Solution {
public:
    // simple logic using the maxheap
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if the k ==1 then return orginal vector
        if (k == 1) {
            return nums;
        }
        priority_queue<pair<int, int>> pq;
        // stores starting k element onto the max heap
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        vector<int> ans;
        //top of the max heap is the maximum element in the window starting k
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            // push the element in the priority queue
            pq.push({nums[i],i});
            // validating the element is maxheap top element in the  valid window 
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
}
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
