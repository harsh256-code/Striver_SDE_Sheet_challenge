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
        if(head==NULL or n==0) return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *fast = start,*slow = start;
        for(int i = 1;i<=n;i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow ->next = slow->next->next;
        return start->next;
    }
};
