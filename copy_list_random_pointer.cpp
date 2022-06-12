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
        if(!head)return head;
        Node *temp = head;
        while(temp){
            Node *nex = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nex;
            temp = temp->next->next;
            
        }
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
               
            }
            temp = temp->next->next;
        }
        Node *dummy = new Node(0);
        Node *x= dummy;
        Node *curr = head;
        while(curr){
            Node *nex = curr->next->next;
            x->next = curr->next;
            curr->next = nex;
            x= x->next;
            curr = curr->next;
        }
        return dummy->next;
        
        
    }
};
