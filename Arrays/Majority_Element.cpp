// Problem: Majority Element (an element that appears more than n/2 times (count(elemtent)>n/2))
// Link: https://leetcode.com/problems/majority-element/
// Time: O(n) -> Two sequential linear passes, so O(2n) which simplifies to O(n)
// Space: O(1)

// Approach:
// Phase 1 (Boyer-Moore Voting): Track a candidate element 'el' and a counter 'cnt'. 
// Match increases the count, mismatch decreases it. Reset candidate when count hits zero.
// Phase 2 (Verification): Iterate through the array a second time to count the actual occurrences 
// of the candidate to guarantee it strictly appears more than n / 2 times.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = 0;
        int cnt = 0;
        
        // Phase 1: Finding the potential majority candidate
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt = 1;
            } else if (nums[i] == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        // Phase 2: Cross-Verification (Crucial step for a robust solution)
        int actual_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                actual_count++;
            }
        }
        
        // If the actual count is greater than n / 2, it's verified
        if (actual_count > n / 2) {
            return el;
        }
        
        return -1; // Return -1 if no true majority element exists
    }
};