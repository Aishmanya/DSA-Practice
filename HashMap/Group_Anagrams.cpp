// Problem: Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Time: O(N * K log K) -> N is number of strings, K is maximum length of a string
// Space: O(N * K) -> To store strings inside the hash map

// Approach:
// Anagrams yield the exact same string when sorted.
// Iterate through each string, sort a copy of it to use as a key in an unordered_map.
// Group original strings into vectors mapped to their corresponding sorted keys.
// Extract all grouped vectors into the final 2D result.