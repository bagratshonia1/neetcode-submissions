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
        ogToCopy[nullptr] = nullptr;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            ogToCopy[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node* copy2 = ogToCopy[curr];
            copy2->next = ogToCopy[curr->next];
            copy2->random = ogToCopy[curr->random];
            curr = curr->next;
        }
        return ogToCopy[head];

    }
};
