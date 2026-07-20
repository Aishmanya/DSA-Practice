// Problem: Maximum Subarray (Kadane's Algorithm with Indices)
// Link: https://leetcode.com/problems/maximum-subarray/
// Time: O(n)
// Space: O(1)

// Approach:
// Use Kadane's Algorithm to find the maximum subarray sum in a single pass.
// Track the start of a potential subarray whenever the current running sum is reset to 0.
// Whenever a new maximum sum is discovered, update the global maximum ('maxi') and lock in the final 'ansStart' and 'ansEnd' indices.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        long long maxi = INT_MIN; // Tracks the maximum subarray sum found so far
        long long sum = 0;        // Tracks the running sum of the current subarray
        
        int start = 0;            // Temporary start index of the current subarray
        int ansStart = -1;        // Final starting index of the maximum subarray
        int ansEnd = -1;          // Final ending index of the maximum subarray
        
        for (int i = 0; i < n; i++) {
            // If sum is 0, it means we are starting a new subarray block
            if (sum == 0) {
                start = i;
            }
            
            sum += nums[i];
            
            // If current running sum beats the historical maximum
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            // If running sum becomes negative, discard it and reset to 0
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Note: 'maxi' holds the maximum sum. 
        // 'ansStart' and 'ansEnd' give the boundaries of that subarray.
        return maxi;
    }
};