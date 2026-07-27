// Problem: Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Time: O(n)
// Space: O(1)

// Approach:
// Use Fast and Slow pointers (Tortoise and Hare technique).
// Slow moves 1 step while Fast moves 2 steps at a time.
// When Fast reaches the end (or NULL), Slow will be pointing directly at the middle node.