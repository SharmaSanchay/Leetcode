//Leetcode->150(https://leetcode.com/problems/evaluate-reverse-polish-notation/)
class Solution {
public:
    int evalRPN(vector<string>& token) {
        // Initialize a stack to store intermediate results
        stack<int> st;

        // Loop through each token in the input vector
        for (int i = 0; i < token.size(); i++) {
            // If the token is an operator, perform the corresponding operation
            if (token[i] == "+" || token[i] == "*" || token[i] == "/" || token[i] == "-") {
                // Pop the top two values from the stack
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                // Apply the operator to the two values and push the result back onto the stack
                if (token[i] == "+")
                    st.push(val2 + val1);
                else if (token[i] == "*")
                    st.push(val2 * val1);
                else if (token[i] == "/")
                    st.push(val2 / val1);
                else
                    st.push(val2 - val1);
                
            } else {
                // If the token is a number, convert it to an integer and push it onto the stack
                int val = stoi(token[i]);
                st.push(val);
            }
        }

        // The final result of the RPN expression is the top value on the stack
        return st.top();
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
