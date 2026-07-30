// Problem: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Time: O(n)
// Space: O(n)

// Approach:
// Use a stack to track open brackets. 
// For every closing bracket, check if it matches the top of the stack.
// Return true if the stack is completely empty at the end.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, there's no matching open bracket
                if (st.empty()) return false;

                char topChar = st.top();
                if ((c == ')' && topChar == '(') ||
                    (c == '}' && topChar == '{') ||
                    (c == ']' && topChar == '[')) {
                    st.pop(); // Matched successfully
                } else {
                    return false; // Mismatched bracket type
                }
            }
        }

        // Valid only if all opened brackets were properly closed
        return st.empty();
    }
};