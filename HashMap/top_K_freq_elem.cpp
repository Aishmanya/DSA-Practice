// Problem: Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Time: O(n) -> Counting frequencies takes O(n), Bucket Sort takes O(n)
// Space: O(n) -> Hash map and Buckets take extra space

// Approach:
// 1. Build a frequency map for all elements.
// 2. Create buckets where index represents the frequency and stores numbers with that frequency.
// 3. Iterate backward through buckets (from highest frequency down) to collect top K elements.
