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