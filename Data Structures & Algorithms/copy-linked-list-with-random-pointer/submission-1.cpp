/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ogToCopy;
        ogToCopy[nullptr] = nullptr; // we add the null pointer for the edge case
        Node* curr = head;
        //create a map where each key is an original node from the original linked list, and every value is a copy of that original node, but without the ->next and ->random links
        while(curr){
            Node* copy = new Node(curr->val);
            ogToCopy[curr] = copy;
            curr = curr->next;
        }
        //since we created the copies, reset the curr pointer to head
        curr = head;
        //now lets go through the list once again and for each element's copy lets link them to their corresponding ->random and ->next pointers
        while(curr){
            //we get the copied node from the list
            Node* copy2 = ogToCopy[curr];
            //the next pointer for that would be the next pointer of the original node (curr), and ogToCopy[curr->next] gives as the copy of it
            copy2->next = ogToCopy[curr->next];
            //the random of the copy, is the random of the original, but we need to map the copy node to the random node's copy.
            copy2->random = ogToCopy[curr->random];
            curr = curr->next;
        }
        return ogToCopy[head];

    }
};
