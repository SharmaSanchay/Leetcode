//Leetcode->901(https://leetcode.com/problems/online-stock-span/)
class StockSpanner {
public:
    // Define a type alias for a pair of integers
    typedef pair<int, int> P;
    
    // Stack to store pairs of (price, span)
    stack<P> st;

    // Constructor
    StockSpanner() {
        // No initialization needed
    }
    
    // Function to process the next price
    int next(int price) {
        int span = 1; // Initialize span to 1
        
        // While the stack is not empty and the top price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the top element to the current span
            st.pop(); // Pop the top element from the stack
        }
        
        // Push the current price and its span onto the stack
        st.push({price, span});
        
        // Return the span for the current price
        return span;
    }
};
/*
Time Complexity->O(1)
Space Complexity->O(N)
*/
