// Linked List cycle   - Cycle tab hoti hai jab list ki koi node aage chal kar kisi purani node se wapas connect ho jaye, 
// jisse list ka ending node NULL par pahunchne ke bajaye infinite loop mein chala jaye.
// ~~ NOT necessary ki head ko he point kare !

// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Time: O(n)
// Space: O(1)

// Approach:
// Use Fast and Slow pointers (Floyd's Cycle-Finding Algorithm).
// Move 'slow' by 1 step and 'fast' by 2 steps.
// If there is a cycle, 'fast' will eventually catch up and meet 'slow'.
// If 'fast' reaches NULL or fast->next becomes NULL, no cycle exists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //checking base case for empty node or single node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        while (fast!=NULL && fast->next!= NULL ){
            slow= slow->next;
            fast=fast->next->next;
            if(fast==slow){return true;}
        }

        return false;
        
    }
};





// ~~~~~~~~~~~~~ This method will work for cycle at head not in general ~~~~~~~~~~~~~~~~~~
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        while(temp!= NULL || temp->next!= NULL ){
            if (temp->next=head){return true;}
            temp=temp->next;
        }
        return false;
        
    }
};