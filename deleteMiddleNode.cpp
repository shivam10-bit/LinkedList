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
    ListNode* deleteMiddle(ListNode* head) {
        // Handle edge case: if the list is empty or has only one node
        if (!head || !head->next) {
            return nullptr;
        }

        // Use a dummy node to handle the case where the head might be the middle node in a very short list
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;

        // Move the fast pointer two steps and the slow pointer one step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // At the end of the loop, 'slow' will be the node right before the middle node
        // Delete the middle node by adjusting the pointers
        ListNode* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode; // Free the memory of the deleted node

        return dummy->next;
    }
};