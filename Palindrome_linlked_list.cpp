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
    private:
    ListNode* reverse(ListNode *head){
        ListNode *prev = 0,*curr = head,*nex = head;
        while(curr){
            nex= nex->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)return true;
        ListNode *slow = head,*fast = head;
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *dummy = head;
        while(slow){
            if(dummy->val != slow->val)return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
        
    }
};
