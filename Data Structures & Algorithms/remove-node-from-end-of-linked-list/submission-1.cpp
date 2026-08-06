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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* temp = head;
        int size = 0;

        //finding the size of the Linked List
        while(temp){
            temp = temp->next;
            size++;
        }

        //Which element from the front should be removed
        int removeFront = size - n;

        //creating a dummy node before head node, to safely
        //remove the node
        ListNode* dummy = new ListNode(0, head);

        //two temporary nodes to trace the linked list
        ListNode* temp1 = dummy;
        ListNode* temp2 = head;

        //we trace the linked list so temp2 stops at the
        //node which should be removed
        for(int i = 0; i < removeFront; i++){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        //removing the node
        temp1->next = temp2->next;
        //we return dummy->next, because, what if the head element
        //was the one that has been removed
        return dummy->next;
    }
};
