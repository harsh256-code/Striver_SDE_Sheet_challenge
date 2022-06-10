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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) return NULL;
        if(!list1)return list2;
        if(!list2) return list1;
        ListNode *temp = 0,*ans;
        if(list1->val>list2->val) swap(list1,list2);
        
        ans = list1;
        while(list1 and list2){
            if(list1->val<=list2->val){
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                swap(list1, list2);
                temp = temp->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;
        return ans;
    }
};
