// Problem: Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Time: O(n) - Every index is pushed and popped at most once
// Space: O(n) - Monotonic stack storage

// Approach:
// Use a monotonic decreasing stack to store indices of temperatures.
// When encountering a warmer temperature, pop indices from the stack 
// and calculate the difference in days.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // Stores indices of temperatures

        for (int i = 0; i < n; ++i) {
            // Process all previous colder days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex;
            }
            
            // Push current day's index
            st.push(i);
        }

        return answer;
    }
};