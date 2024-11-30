//Leetcode->632 (https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // Number of lists

        // Priority queue to maintain the smallest elements from each list.
        // Each element in the priority queue is a vector of {element, listIdx, idx}
        // Where element is the value, listIdx is the index of the list it came from, and idx is the index within that list.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN; // Initialize maxEl to keep track of the maximum element in the current range.
        
        // Push the first element of each list into the priority queue and update maxEl.
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        // Initialize resultRange with a large range to start.
        vector<int> resultRange = {-1000000, 1000000};

        // Process elements in the priority queue until it becomes empty.
        while(!pq.empty()) {
            vector<int> curr = pq.top(); // Get the smallest element from the priority queue.
            pq.pop(); // Remove it from the queue.

            int minEl = curr[0]; // The smallest element (current minimum in the range).
            int listIdx = curr[1]; // The list index from which this element came.
            int idx = curr[2]; // The index within the list.

            // Update the resultRange if the current range is smaller.
            if(maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // If there are more elements in the current list, push the next element into the priority queue.
            if(idx + 1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx + 1];
                pq.push({nextElement, listIdx, idx + 1});
                maxEl = max(maxEl, nextElement); // Update maxEl with the new element.
            } else {
                break; // If any list is exhausted, we can break the loop.
            }
        }

        return resultRange; // Return the smallest range found.
    }
};

/*
Time Complexity->O((n+k)logk)
Space Complexity->O(k)
*/







