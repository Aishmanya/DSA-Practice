// Problem: Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Time: O(n)
// Space: O(1)

// Approach:
// Use Fast and Slow pointers (Tortoise and Hare technique).
// Slow moves 1 step while Fast moves 2 steps at a time.
// When Fast reaches the end (or NULL), Slow will be pointing directly at the middle node.

// Floyd’s Cycle-Finding Algorithm (also known as the Tortoise and Hare Algorithm).

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){ //maintain this order only as pehle 1st condn check hota in && then proceed karta
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        //not slow->value coz slow is a pointer pointing to a value only na and also
    }
};