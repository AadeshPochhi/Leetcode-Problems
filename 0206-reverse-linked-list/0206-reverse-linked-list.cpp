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
    ListNode* newHead=NULL;
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL){
            return head;
        }
        ListNode *prev=NULL;
        reverseListHelper(head,prev);
        return newHead;
    }
    void reverseListHelper(ListNode* head,ListNode* prev){
        if(head==NULL) return;
        if(head->next==NULL){
            newHead=head;
        }
        ListNode* temp=head->next;
        head->next=prev;
        
        reverseListHelper(temp,head);
        
    }
};