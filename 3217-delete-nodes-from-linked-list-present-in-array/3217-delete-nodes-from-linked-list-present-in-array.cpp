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
    ListNode* deleteNode(ListNode* head, ListNode* element){
        if(head==NULL) return head;
        if(head->val==element->val){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode* curr=head->next;
        ListNode* prev=head;
        while(curr){
            if(curr==element){
                prev->next=curr->next;
                delete curr;
                break;
            }
            prev=head;
            curr=curr->next;
            
        }
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         set<int> st(nums.begin(), nums.end()); 
         ListNode* dummy = new ListNode(0, head); 
        ListNode* temp = dummy;

        while (temp && temp->next) { 
            if (st.find(temp->next->val) != st.end()) { 
                temp->next = deleteNode(temp->next, temp->next); 
            } else {
                temp = temp->next; 
            }
        }

        head = dummy->next; // Update head to the new list
        delete dummy; // Clean up the dummy node
        return head;
        
    }
};