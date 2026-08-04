// Problem: Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Time: O(n) - Every index is pushed and popped at most once
// Space: O(n) - Monotonic stack storage

// Approach:
// Use a monotonic decreasing stack to store indices of temperatures.
// When encountering a warmer temperature, pop indices from the stack 
// and calculate the difference in days.

