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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr1=head;
        ListNode* curr2=head->next;
        ListNode* f=head;
        ListNode* s=head->next;
        while(curr2!=NULL && curr2->next!=NULL){
            ListNode* temp=curr1->next;
            curr1->next=curr2->next;
            curr2->next=temp->next->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        curr1->next=s;
        return f;
    }
};