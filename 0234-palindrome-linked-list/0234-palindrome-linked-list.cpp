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
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        //Your code here
        ListNode* head2=head;
        int n=0;
        while(head2!=NULL){
            n++;
            head2=head2->next;
        }
        head2=head;
        for(int i=0;i<(n+1)/2;i++){
            head2=head2->next;
        }
        head2=rev(head2);
        while(head2!=NULL && head->val==head2->val){
            head=head->next;
            head2=head2->next;
        }
        return head2==NULL;
        
    }
};