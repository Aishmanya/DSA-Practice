// Problem: Running Sum of 1d Array
// Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Time: O(n)
// Space: O(1)

// Approach:
// Iterate through the array starting from index 1.
// Update each element in-place by adding the value of the previous element to it.
// This effectively accumulates the running sum without using extra memory.

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Start from index 1 because the 0th element's running sum is just itself
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1]; 
        }
        return nums;
    }
};


// OR 
// But this takes time complexity of O(n) for that extra prefix array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        int sum=0;
        for (int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        return prefix;
        
    }
};


