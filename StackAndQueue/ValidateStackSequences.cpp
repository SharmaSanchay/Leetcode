//Leetcode->946(https://leetcode.com/problems/validate-stack-sequences/)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Initialize an empty stack to simulate the push/pop operations
        stack<int> st;
        int j = 0; // Pointer for the popped sequence
        
        // Iterate through each element in the pushed sequence
        for (int i = 0; i < pushed.size(); i++) {
            // Push the current element onto the stack
            st.push(pushed[i]);
            
            // Check if the top of the stack matches the current element in the popped sequence
            // Keep popping from the stack while the top matches the popped sequence
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++; // Move to the next element in the popped sequence
            }
        }
        
        // If j has reached the end of the popped sequence, the sequences are valid
        return j >= popped.size();
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
