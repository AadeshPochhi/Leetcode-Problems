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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp=head;
        bool v;
        int counter=0;
        while(temp){
            if((count(nums.begin(),nums.end(),temp->val)>0) && v==false){
                counter++;
                v=true;
                
            }
            else if(count(nums.begin(),nums.end(),temp->val)==0){
                v=false;
            }
            temp=temp->next;
        }
        return counter;
    }
};