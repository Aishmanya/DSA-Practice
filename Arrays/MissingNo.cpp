// Given an array containing n-1 distinct integers taken from the range 1 to n (or 0 to n), 
// find the one number that is missing from the sequence

// OPTIMAL SOLUTION 1:-

int missing_no(int nums[], int n) {
    // 1. Calculate the expected sum of numbers from 1 to n using the math formula
    // This avoids the extra addition inside the loop!
    int expected_sum = (n * (n + 1)) / 2;
    
    int actual_sum = 0;
    // 2. The array only has n - 1 elements because one is missing
    for (int i = 0; i < n - 1; i++) {
        actual_sum += nums[i];
    }
    
    // 3. Return the difference
    return expected_sum - actual_sum;
}

// TIME COMPLEXITY: O(n) as we loop through (n-1) or n once

// SPACE COMPLEXITY: O(1)
//   Why? We only allocate a few integer variables ('expected_sum', 'actual_sum').
//   No extra memory (like arrays or vectors)



// OPTIMAL SOLUTION 2:-  (better one)

/**
 * XOR Logic
 * xor of same no.s is 0 (5^5 =0)
 * xor of anything with 0 is the no. itself (8^0 =8)
 */

int missing_no_xor(int nums[], int n) {
    int xor_all = 0;
    int xor_new = 0;
    
    // 1. XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor_all ^= i;
    }
    
    // 2. XOR all elements present in the array (size is n-1)
    for (int i = 0; i < n - 1; i++) {
        xor_new ^= nums[i];
    }
    
    // The xor of both value is the missing number
    return xor_all^xor_new;
}

/*
  TIME COMPLEXITY: O(n) - We iterate through the range and array linearly.
  SPACE COMPLEXITY: O(1) - Only one variable ('xor_all') is used.
*/