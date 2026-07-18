// Problem: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/
// Time: O(n)
// Space: O(1)

// Approach:
// First, make a forward pass (Prefix) to store the product of all elements to the left of each index directly in the output array.
// Then, make a backward pass (Suffix) using a single running variable to multiply the elements to the right, calculating the final product in-place.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // 1. Prefix Pass: Calculate product of all elements to the left
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = left_product;
            left_product *= nums[i];
        }
        
        // 2. Suffix Pass: Multiply with the product of all elements to the right
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }
        
        return ans;
    }
};